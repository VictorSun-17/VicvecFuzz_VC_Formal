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
#include "Vector_create.h"
#include "Set_create.h"
#include "List_create.h"
#include "Deque_create.h"
#include "Array_create.h"
#include "Queue_create.h"


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



// Function to generate a random STL container operation
std::string generateRandomSTLCode() {
	std::string code;
	int choice = random_Int(1, 5);
	int times = random_Int(1, 10);
	int random_value = random_Int(1, 100);
	int number_of_vecs = random_Int(1, 3);
	int number_of_sets = random_Int(1, 3);
	int number_of_lists = random_Int(1, 3);
	int number_of_deques = random_Int(1, 3);
	int number_of_arrays = random_Int(1, 3);
	int i = 0;
	int n = 0;
	//std::string random_ops = random_vec_op();

	//switch (random_Int(1,2) {
	//case 1: // Vector operations
	code += create_vec(number_of_vecs);



	/*      code += random_ops;*/

//	break;
//case 2:

	//code += create_set(number_of_sets);
	code += create_list(number_of_lists);
	code += create_deque(number_of_deques);
	code += create_array(number_of_arrays);

	/*code += random_set_op(number_of_sets);*/

	//break;

	//code += random_transition(number_of_vecs, number_of_sets);

//case 3: // Map operations
//	code += "std::map<int, std::string> m;\n";
//	code += "m[1] = \"one\";\n";
//	code += "m[2] = \"two\";\n";
//	code += "for (const auto& p : m) std::cout << p.first << : << p.second << '\\n';\n";
//	break;

//case 4: // Queue operations
//	code += "std::queue<int> q;\n";
//	code += "q.push(1);\n";
//	code += "q.push(2);\n";
//	code += "q.push(3);\n";
//	code += "while (!q.empty()) {\n";
//	code += "    std::cout << q.front() << ' ';\n";
//	code += "    q.pop();\n";
//	code += "}\n";
//	code += "std::cout << std::endl;\n";
//	break;

//case 5: // Random algorithm usage
//	code += "std::vector<int> vec = {5, 3, 4, 1, 2};\n";
//	code += "std::sort(vec.begin(), vec.end());\n";
//	code += "for (int x : vec) std::cout << x << ' ';\n";
//	code += "std::cout << std::endl;\n";
//	break;
//}
	code += "	uint32_t hash_result = simple_hash(buffer.data(), buffer.size());\n";
	code += "	unsigned int out = hash_result;\n";

return code;
}



int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	// Generate random C++ code
	std::string randomCode = generateRandomSTLCode();

	// Write the random code to a file
	std::ofstream outFile("random_stl_program.cpp");
	if (outFile.is_open()) {
		outFile << "#include <iostream>\n";
		outFile << "#include <vector>\n";
		outFile << "#include <set>\n";
		outFile << "#include <map>\n";
		outFile << "#include <queue>\n";
		outFile << "#include <algorithm>\n";
		outFile << "#include <initializer_list>\n";
		outFile << "#include <list>\n";
		outFile << "#include <array>\n";
		outFile << "#include <string>\n";
		outFile << "#include <fstream>\n\n";
		outFile << "#ifdef JASPER_C\n";
		outFile << "#include <jasperc.h>\n";
		outFile << "#endif\n\n";
		//outFile << "int RdmInt(int min, int max) {\n";
		//outFile << "	if (max - min + 1 != 0)\n";
		//outFile << "		return min + rand() % (max - min + 1);\n";
		//outFile << "	else\n";
		//outFile << "		return 0;\n";
		//outFile << "}\n\n";
		outFile << "uint32_t simple_hash(const void* data, size_t len) {\n";
		outFile << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
		outFile << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
		outFile << "    for (size_t i = 0; i < len; ++i) {\n";
		outFile << "        hash ^= bytes[i];\n";
		outFile << "        hash *= 16777619u; // FNV prime\n";
		outFile << "    }\n";
		outFile << "    return hash;\n";
		outFile << "}\n\n";
		outFile << "template <typename T>\n";
		outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
		outFile << "    const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());\n";
		outFile << "    buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));\n";
		outFile << "}\n\n";

		//outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<std::set<int>>& vec) {\n";
		//outFile << "	for (const auto& s : vec) {\n";
		//outFile << "		// 先写入 set 的大小\n";
		//outFile << "		uint32_t size = s.size();";
		//outFile << "		buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&size), reinterpret_cast<const uint8_t*>(&size) + sizeof(size));\n";
		//outFile << "		// 然后写入 set 的每个元素\n";
		//outFile << "		for (int val : s) {\n";
		//outFile << "			buffer.insert(buffer.end(), reinterpret_cast<const uint8_t*>(&val), reinterpret_cast<const uint8_t*>(&val) + sizeof(val));\n";
		//outFile << "		}\n";
		//outFile << "	}\n";
		//outFile << "}\n";

		outFile << "void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {\n";
		outFile << "	for (bool b : vec) {\n";
		outFile << "		buffer.push_back(b ? 1 : 0);\n";
		outFile << "	}\n";
		outFile << "}\n\n";
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
		outFile2 << "#include <iostream>\n";
		outFile2 << "#include <vector>\n";
		outFile2 << "#include <set>\n";
		outFile2 << "#include <map>\n";
		outFile2 << "#include <queue>\n";
		outFile2 << "#include <algorithm>\n";
		outFile2 << "#include <initializer_list>\n";
		outFile2 << "#include <list>\n";
		outFile2 << "#include <array>\n";
		outFile2 << "#include <string>\n";
		outFile2 << "#include <fstream>\n";
		outFile2 << "#include \"Hector.h\"\n";
		outFile2 << "#include <stdint.h>\n\n";
		outFile2 << "uint32_t simple_hash(const void* data, size_t len) {\n";
		outFile2 << "    const uint8_t* bytes = static_cast<const uint8_t*>(data);\n";
		outFile2 << "    uint32_t hash = 2166136261u; // FNV offset basis\n";
		outFile2 << "    for (size_t i = 0; i < len; ++i) {\n";
		outFile2 << "        hash ^= bytes[i];\n";
		outFile2 << "        hash *= 16777619u; // FNV prime\n";
		outFile2 << "    }\n";
		outFile2 << "    return hash;\n";
		outFile2 << "}\n\n";

		outFile2 << "template <typename T>\n";
		outFile2 << "void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {\n";
		outFile2 << "    if (vec.empty()) return;\n";
		outFile2 << "    size_t old_size = buffer.size();\n";
		outFile2 << "    size_t append_size = vec.size() * sizeof(T);\n";
		outFile2 << "    buffer.resize(old_size + append_size);\n";
		outFile2 << "    std::memcpy(buffer.data() + old_size, vec.data(), append_size);\n";
		outFile2 << "}\n\n";

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






	return 0;
}