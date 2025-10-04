#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
//#include <format>
#include <initializer_list>
#include <string>
#include "Random_program.h"



enum class TypeKind { SignedIntegral, UnsignedIntegral, Floating, Boolean };

std::string random_transition(int vec_numbers, int set_numbers) {
	std::string code;
	int n = random_Int(1, 2);


	for (int i = 1; i <= n; i++)
	{
		int index_set = random_Int(1, set_numbers);
		int index_vec = random_Int(1, vec_numbers);
		switch (random_Int(1, 2)) {
		case 1:

			code += "std::set <int> set_" + std::to_string(set_numbers + i) + "(vec_" + std::to_string(index_vec) + ".begin(), vec_" + std::to_string(index_vec) + ".end()); \n";
		case 2:
			code += "std::vector<int> vec_" + std::to_string(vec_numbers + i) + "(set_" + std::to_string(index_set) + ".begin(), set_" + std::to_string(index_set) + ".end()); \n";
		}
	}



	return code;
}

const std::vector<std::string>& op_pool(TypeKind kind) {
	static const std::vector<std::string> signed_integral_ops = {
		// 算术
		"return a + b;\n",
		"return a - b;\n",
		"return a * b;\n",
		//"if (b != 0) return a / b;\n",
		//"if (b != 0) return a % b;\n",

		// 比较（返回 bool，若你希望统一返回整型，可包一层 (a<b)?1:0）
		"return a == b;\n",
		"return a != b;\n",
		"return a <  b;\n",
		"return a <= b;\n",
		"return a >  b;\n",
		"return a >= b;\n",

		//// 按位（先转无符号，避免 UB）
		//"using U = std::make_unsigned_t<decltype(a)>;\nreturn static_cast<U>(a) & static_cast<U>(b);\n",
		//"using U = std::make_unsigned_t<decltype(a)>;\nreturn static_cast<U>(a) | static_cast<U>(b);\n",
		//"using U = std::make_unsigned_t<decltype(a)>;\nreturn static_cast<U>(a) ^ static_cast<U>(b);\n",
		//"using U = std::make_unsigned_t<decltype(a)>;\nreturn ~static_cast<U>(a);\n",

		//// 移位（有符号 → 无符号，且限幅）
		//"using U = std::make_unsigned_t<decltype(a)>;\nauto sh = (static_cast<U>(b) & (sizeof(U)*CHAR_BIT - 1));\nreturn static_cast<U>(a) << sh;\n",
		//"using U = std::make_unsigned_t<decltype(a)>;\nauto sh = (static_cast<U>(b) & (sizeof(U)*CHAR_BIT - 1));\nreturn static_cast<U>(a) >> sh;\n",

		// 可选：带副作用（谨慎）
		//"return ++a;\n",
		//"return --a;\n",
		"return a++;\n",
		"return a--;\n",
		"return (a += b);\n",
		"return (a -= b);\n",
		"return (a *= b);\n",
		//"if (b != 0) return (a /= b);\n",
		//"if (b != 0) return (a %= b);\n",
	};

	// —— 无符号整数池（unsigned 系）——
	static const std::vector<std::string> unsigned_integral_ops = {
		// 算术
		"return a + b;\n",
		"return a - b;\n",
		"return a * b;\n",
		//"if (b != 0) return a / b;\n",
		//"if (b != 0) return a % b;\n",

		// 比较
		"return a == b;\n",
		"return a != b;\n",
		"return a <  b;\n",
		"return a <= b;\n",
		"return a >  b;\n",
		"return a >= b;\n",

		// 按位（无符号可直接做）
		"return a & b;\n",
		"return a | b;\n",
		"return a ^ b;\n",
		"return ~a;\n",

		// 移位（限幅）
		"return a << (b & (sizeof(a)*CHAR_BIT - 1));\n",
		"return a >> (b & (sizeof(a)*CHAR_BIT - 1));\n",

		// 可选：带副作用
		"return ++a;\n",
		"return --a;\n",
		"return a++;\n",
		"return a--;\n",
		"return (a += b);\n",
		"return (a -= b);\n",
		"return (a *= b);\n",
		//"if (b != 0) return (a /= b);\n",
		//"if (b != 0) return (a %= b);\n",
	};

	static const std::vector<std::string> floating_ops = {
		"return a + b;\n",
		"return a - b;\n",
		"return a * b;\n",
		//"if (b != 0.0) return a / b;\n",
		"return a == b;\n",
		"return a != b;\n",
		"return a <  b;\n",
		"return a <= b;\n",
		"return a >  b;\n",
		"return a >= b;\n",
		"return ++a;\n",
		"return --a;\n",
		"return a++;\n",
		"return a--;\n",
		"return (a += b);\n",
		"return (a -= b);\n",
		"return (a *= b);\n",
		//"if (b != 0.0) return (a /= b);\n",
	};

	static const std::vector<std::string> boolean_ops = {
		"return a && b;\n",
		"return a || b;\n",
		"return !a;\n",
		"return a == b;\n",
		"return a != b;\n",
	};

	switch (kind) {
	case TypeKind::SignedIntegral:   return signed_integral_ops;
	case TypeKind::UnsignedIntegral: return unsigned_integral_ops;
	case TypeKind::Floating:         return floating_ops;
	case TypeKind::Boolean:          return boolean_ops;
	}
	return boolean_ops;
}

std::string gen_block(TypeKind kind) {
	const auto& pool = op_pool(kind);
	int idx = random_Int(0, static_cast<int>(pool.size()) - 1);
	return pool[idx];
}

std::pair<std::string, std::string> arithmatic_block_creation(int index, std::vector<container_record> container_records, std::vector<int> number_of_containers) {
	std::string block;
	std::string call_func;

	for (int i = 0; i < index; i++)
	{
		int length_1 = -1;
		int length_2 = -1;
		std::string type_1 = {};
		std::string type_2 = {};
		int container_id_1 = -1;
		int container_id_2 = -1;
		std::string container_type_1 = {};
		std::string container_type_2 = {};

		switch (random_Int(1, 3)) {
		case 1: //vector
			container_id_1 = random_Int(0, number_of_containers[0] - 1);
			length_1 = container_records[container_id_1].vec_length;
			type_1 = container_records[container_id_1].vec_type;
			container_type_1 = "vec_";
			break;
		case 2: //array
			container_id_1 = random_Int(0, number_of_containers[1] - 1);
			length_1 = container_records[container_id_1].ary_length;
			type_1 = container_records[container_id_1].ary_type;
			container_type_1 = "ary_";
			break;
		case 3: //deque
			container_id_1 = random_Int(0, number_of_containers[2] - 1);
			length_1 = container_records[container_id_1].deq_length;
			type_1 = container_records[container_id_1].deq_type;
			container_type_1 = "deq_";
			break;
		}

		switch (random_Int(1, 3)) {
		case 1: //vector
			container_id_2 = random_Int(0, number_of_containers[0] - 1);
			length_2 = container_records[container_id_2].vec_length;
			type_2 = container_records[container_id_2].vec_type;
			container_type_2 = "vec_";
			break;
		case 2: //array
			container_id_2 = random_Int(0, number_of_containers[1] - 1);
			length_2 = container_records[container_id_2].ary_length;
			type_2 = container_records[container_id_2].ary_type;
			container_type_2 = "ary_";
			break;
		case 3: //deque
			container_id_2 = random_Int(0, number_of_containers[2] - 1);
			length_2 = container_records[container_id_2].deq_length;
			type_2 = container_records[container_id_2].deq_type;
			container_type_2 = "deq_";
			break;
		}
		block += "auto arith_block_" + std::to_string(i) + "(" + type_1 + " a" + ", " + type_2 + " b){\n";
		if (type_1 == "float" or type_1 == "double" or type_2 == "float" or type_2 == "double") {
			block += gen_block(TypeKind::Floating);
		}
		else if (type_1 == "bool" or type_2 == "bool")
		{
			block += gen_block(TypeKind::Boolean);
		}
		else if (type_1 == "int" or type_1 == "short" or type_1 == "char" or type_1 == "long"
			or type_2 == "int" or type_2 == "short" or type_2 == "char" or type_2 == "long") {
			block += gen_block(TypeKind::SignedIntegral);
		}

		else {
			block += gen_block(TypeKind::UnsignedIntegral);
		}
		block += "}\n";
		call_func += "	auto arith_result_" + std::to_string(i) + "= arith_block_" + std::to_string(i) +
			"(" + container_type_1 + std::to_string(container_id_1) + "[" + std::to_string(random_Int(0, length_1 - 1)) + "], "
			+ container_type_2 + std::to_string(container_id_2) + "[" + std::to_string(random_Int(0, length_2 - 1)) + "]);\n";
		call_func += "	append_data(buffer, arith_result_" + std::to_string(i) + ");\n";
	}



	return{ block,call_func };

}


// Function to generate a random STL container operation
std::pair<std::string, std::string> generateRandomSTLCode() {
	std::string code;
	std::string block;
	std::vector<container_record> container_records(10);
	int choice = random_Int(1, 5);
	int times = random_Int(1, 10);
	int random_value = random_Int(1, 100);
	int number_of_vecs = random_Int(10, 10);
	int number_of_sets = random_Int(10, 10);
	int number_of_lists = random_Int(10, 10);
	int number_of_deques = random_Int(10, 10);
	int number_of_arrays = random_Int(10, 10);
	int number_of_queues = random_Int(10, 10);
	int number_of_unordered_sets = random_Int(10, 10);
	int number_of_maps = random_Int(10, 10);
	int number_of_unordered_maps = random_Int(10, 10);
	int number_of_multimaps = random_Int(10, 10);
	int number_of_stack = random_Int(10, 10);
	int number_of_bitset = random_Int(10, 10);
	int number_of_arith_block = random_Int(1, 1);

	std::vector<int> number_of_containers = { number_of_vecs ,number_of_arrays,number_of_deques,number_of_queues,
		number_of_sets,number_of_lists,number_of_maps,number_of_multimaps,number_of_stack };
	//int i = 0;
	//int n = 0;
	auto [vec_init, vec_op, vec_records] = create_vec(number_of_vecs);
	auto [ary_init, ary_op, ary_records] = create_array(number_of_arrays);
	auto [deq_init, deq_op, deq_records] = create_deque(number_of_deques);
	auto [que_init, que_op, que_records] = create_queue(number_of_queues);
	auto [set_init, set_op, set_records] = create_set(number_of_sets);
	auto [list_init, list_op, list_records] = create_list(number_of_lists);
	//code += create_unordered_set(number_of_unordered_sets);
	auto [map_init, map_op, map_records] = create_map(number_of_maps);
	//code += create_unoredered_map(number_of_unordered_maps);
	auto [multimap_init, multimap_op, multimap_records] = create_multimap(number_of_multimaps);
	auto [stack_init, stack_op, stack_records] = create_stack(number_of_stack);

	for (int t = 0; t < vec_records.size(); t++) {
		container_records[t].vec_length = vec_records[t].length;
		container_records[t].vec_type = vec_records[t].type;
	}

	for (int t = 0; t < ary_records.size(); t++) {
		container_records[t].ary_length = ary_records[t].length;
		container_records[t].ary_type = ary_records[t].type;
	}
	for (int t = 0; t < deq_records.size(); t++) {
		container_records[t].deq_length = deq_records[t].length;
		container_records[t].deq_type = deq_records[t].type;
	}

	for (int t = 0; t < que_records.size(); t++) {
		container_records[t].que_length = que_records[t].length;
		container_records[t].que_type = que_records[t].type;
	}
	for (int t = 0; t < set_records.size(); t++) {
		container_records[t].set_length = set_records[t].length;
		container_records[t].set_type = set_records[t].type;
	}

	for (int t = 0; t < list_records.size(); t++) {
		container_records[t].list_length = list_records[t].length;
		container_records[t].list_type = list_records[t].type;
	}
	for (int t = 0; t < map_records.size(); t++) {
		container_records[t].map_length = map_records[t].length;
		container_records[t].map_type_1 = map_records[t].type_1;
		container_records[t].map_type_2 = map_records[t].type_2;
	}

	for (int t = 0; t < multimap_records.size(); t++) {
		container_records[t].multimap_length = multimap_records[t].length;
		container_records[t].multimap_type_1 = multimap_records[t].type_1;
		container_records[t].multimap_type_2 = multimap_records[t].type_2;
	}

	//create arithmatic blocks
	auto [arith_block, arith_call_func] = arithmatic_block_creation(number_of_arith_block, container_records, number_of_containers);

	block += arith_block;

	code += vec_init + ary_init + deq_init + que_init + stack_init + set_init + list_init + map_init + multimap_init;
	code += "\n\n";
	code += "	std::vector<uint8_t> buffer;\n";
	code += "\n\n";
	code += arith_call_func;
	code += "\n\n";
	code += vec_op + ary_op + deq_op + que_op + stack_op + set_op + list_op + map_op + multimap_op;

	code += create_bitset(number_of_bitset);


	code += "	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());\n";
	code += "	unsigned int out = hash_result;\n";

	return { block, code };
}

enum mode {
	Jasper,
	VC_Formal,
};

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	mode active_mode = VC_Formal;
	// Generate random C++ code
	auto [randomblock, randomCode] = generateRandomSTLCode();

	if (active_mode == VC_Formal) {
		// Write the random code to a file
		std::ofstream outFile("random_stl_program.cpp");
		if (outFile.is_open()) {
			outFile << "#include \"random_stl_program_cpp.h\"\n";
			outFile << randomblock;
			outFile << "int main() {\n";

			outFile << randomCode;
			outFile << "    uint32_t result = hash_result;\n";
			outFile << "	std::ofstream outFile(\"rtl_program.sv\");\n";
			outFile << "	if (outFile.is_open()) {\n";
			outFile << "	outFile << \"module add(\\n\";\n";
			outFile << "	outFile << \"  input logic      clock,\\n\";\n";
			outFile << "	outFile << \"  input logic      resetN,\\n\";\n";
			outFile << "	outFile << \"  output logic [31:0] result\\n\";\n";
			outFile << "	outFile << \"  );\\n\";\n";
			outFile << "	outFile << \"  assign result = 32'd\" + std::to_string(result) +\";\\n\";\n";
			outFile << "	outFile << \"endmodule\\n\";\n";
			outFile << "	}\n";
			outFile << "	else {\n";
			outFile << "		std::cerr << \"Error: Unable to create the file.\" << std::endl;\n";
			outFile << "	}\n";
			outFile << "#ifdef JASPER_C\n";
			outFile << "	JASPER_OUTPUT(out);\n";
			outFile << "#endif\n";
			outFile << "    return 0;\n";
			outFile << "}\n";
			outFile.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cpp'." << std::endl;
		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}


		std::ofstream outFile2("random_stl_program.cc");
		if (outFile2.is_open()) {
			outFile2 << "#include \"random_stl_program_cc.h\"\n";

			outFile2 << randomblock;

			outFile2 << "void hector_wrapper() {\n";
			outFile2 << "   uint32_t result;\n";
			outFile2 << "   Hector::registerOutput(\"result\", &result, 8 * sizeof(result));\n";
			outFile2 << "   Hector::beginCapture();\n";
			outFile2 << randomCode;
			outFile2 << "   result = hash_result;\n";
			outFile2 << "   Hector::endCapture();\n";
			outFile2 << "}\n";

			outFile2.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cc'." << std::endl;


		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}
	}

	else if (active_mode == Jasper) {
		// Write the random code to a file
		std::ofstream outFile("random_stl_program.cpp");
		if (outFile.is_open()) {
			outFile << "#include \"random_stl_program.h\"\n";
			outFile << randomblock;
			outFile << "int main() {\n";

			outFile << randomCode;
			outFile << "    uint32_t result = hash_result;\n";
			outFile << "	std::ofstream outFile(\"rtl_program.sv\");\n";
			outFile << "	if (outFile.is_open()) {\n";
			outFile << "	outFile << \"module add(\\n\";\n";
			//outFile << "	outFile << \"  input logic      clock,\\n\";\n";
			//outFile << "	outFile << \"  input logic      resetN,\\n\";\n";
			outFile << "	outFile << \"  output logic [31:0] result\\n\";\n";
			outFile << "	outFile << \"  );\\n\";\n";
			outFile << "	outFile << \"  assign result = 32'd\" + std::to_string(result) +\";\\n\";\n";
			outFile << "	outFile << \"endmodule\\n\";\n";
			outFile << "	}\n";
			outFile << "	else {\n";
			outFile << "		std::cerr << \"Error: Unable to create the file.\" << std::endl;\n";
			outFile << "	}\n";
			//outFile << "#ifdef JASPER_C\n";
			//outFile << "	JASPER_OUTPUT(out);\n";
			//outFile << "#endif\n";
			outFile << "    return 0;\n";
			outFile << "}\n";
			outFile.close();
			std::cout << "Random STL program has been written to 'random_stl_program.cpp'." << std::endl;
		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}


		std::ofstream outFile2("run_program.cpp");
		if (outFile2.is_open()) {
			outFile2 << "#include \"random_stl_program.h\"\n";

			outFile2 << randomblock;
			outFile2 << "int main() {\n";

			outFile2 << randomCode;
			outFile2 << "    unsigned int result = hash_result;\n";
			outFile2 << "#ifdef JASPER_C\n";
			outFile2 << "	JASPER_OUTPUT(result);\n";
			outFile2 << "#endif\n";
			outFile2 << "    return 0;\n";
			outFile2 << "}\n";
			outFile2.close();
			std::cout << "Random STL program has been written to 'run_profram.cpp'." << std::endl;


		}
		else {
			std::cerr << "Error: Unable to create the file." << std::endl;
		}



	}



	return 0;
}