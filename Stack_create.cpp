#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <initializer_list>
#include <string>
#include "Random_program.h"
#include <sstream>
#include <stack>

std::stack<int> create_stack_int(int length = 1) {
	std::stack<int> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push(random_Int(-100, 100));
			break;

		case 2:
			temp.push(random_Bool());
			break;
		}
	}
	return temp;
}

std::stack<float> create_stack_float(int length = 1) {
	std::stack<float> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push(random_Int(-100, 100));
			break;

		case 2:
			temp.push(random_Bool());
			break;

		case 3:
			temp.push(random_Float(-100, 100));
			break;
		}
	}
	return temp;
}

std::stack<double> create_stack_double(int length = 1) {
	std::stack<double> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 4)) {
		case 1:
			temp.push(random_Int(-100, 100));
			break;

		case 2:
			temp.push(random_Bool());
			break;

		case 3:
			temp.push(random_Float(-100, 100));
			break;

		case 4:
			temp.push(random_Double(-100, 100));
			break;
		}
	}
	return temp;
}

std::stack<char> create_stack_char(int length = 1) {
	std::stack<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Char());
	}
	return temp;
}

std::stack<bool> create_stack_bool(int length = 1) {
	std::stack<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Bool());
	}
	return temp;
}
std::stack<unsigned int> create_stack_uint(int length = 1) {
	std::stack<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UInt(0, 100));
	}
	return temp;
}

std::stack<short> create_stack_short(int length = 1) {
	std::stack<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Short(-100, 100));
	}

	return temp;
}

std::stack<unsigned short> create_stack_ushort(int length = 1) {
	std::stack<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UShort(0, 100));
	}

	return temp;
}

std::stack<unsigned char> create_stack_uchar(int length = 1) {
	std::stack<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UChar());
	}

	return temp;
}

std::stack<long> create_stack_long(int length = 1) {
	std::stack<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Long(-100, 100));
	}

	return temp;
}

std::stack<unsigned long> create_stack_ulong(int length = 1) {
	std::stack<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_ULong(0, 100));
	}

	return temp;
}





std::string generate_stack_element(std::string type) {
	std::string op;
	//int stack_elements_num = random_Int(5, 10);
	if (type == "int")
		return std::to_string(random_Int(-100, 100));
	else if (type == "float")
		return std::to_string(random_Float(-100, 100));
	else if (type == "double")
		return std::to_string(random_Double(-100, 100));
	else if (type == "char")
		return std::to_string(random_Char());
	else if (type == "bool")
		return std::to_string(random_Bool());
	else if (type == "unsigned int")
		return std::to_string(random_UInt(0, 100));
	else if (type == "unsigned char")
		return std::to_string(random_UChar());
	else if (type == "short")
		return std::to_string(random_Short(100, 100));
	else if (type == "unsigned short")
		return std::to_string(random_UShort(0, 100));
	else if (type == "long")
		return std::to_string(random_Long(-100, 100));
	else if (type == "unsigned long")
		return std::to_string(random_ULong(0, 100));
}
std::vector<stack_records> merge_records_min_length(
	const std::vector<stack_records>& records1,
	const std::vector<stack_records>& records2
) {
	std::vector<stack_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		stack_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}

std::pair<std::string, std::vector<stack_records>> random_stack_op(int n, std::vector<stack_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<stack_records> local_records = records;
	int random_size = random_Int(0, 19);//specific for VC Formal

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 7)) {
		case 1:
			if (record_1.length < 20) {
				op += "	stack_" + std::to_string(current) + ".push(" + generate_stack_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1* loop_index;
			}
			break;
		case 2:
			if (record_1.length != 0) {
				op += "	stack_" + std::to_string(current) + ".top(); \n";
			}
			break;
		case 3:
			if (record_1.length != 0) {
				op += "	stack_" + std::to_string(current) + ".pop();\n";
				local_records[current].length -= 1* loop_index;
			}
			break;
		case 4:
			if (record_1.length < 20) {
				op += "	stack_" + std::to_string(current) + ".emplace(" + generate_stack_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1* loop_index;
			}
			break;
		case 5:
			op += "	stack_" + std::to_string(current) + ".size();\n";
			break;
		case 6:
			op += "	stack_" + std::to_string(current) + ".empty();\n";
			break;
		case 7:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	stack_" + std::to_string(current) + ".swap(stack_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;

		}
	}



	records = local_records;
	return { op, records };
}


std::string random_stack_loop(int number_of_index, std::vector<stack_records> records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	//std::vector<vector_records> local_records = vec_records;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() > " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() < " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() >= " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() <= " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() == " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (stack_" + std::to_string(current) + ".top() != " + generate_stack_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_stack_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_stack_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_stack_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_stack_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_stack_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_stack_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	index_stack_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
			break;

		}
		//std::cout << op << std::endl;
	}
	return op;
}


std::tuple<std::string, std::string, std::vector<stack_records>> create_stack(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int stack_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	//int stack_rows = 2;// 1 for 1D vector
	//temp vectors
	std::stack<int> temp_int = {};
	std::stack<float> temp_float = {};
	std::stack<double> temp_double = {};
	std::stack<char> temp_char = {};
	std::stack<bool> temp_bool = {};
	std::stack<unsigned int> temp_uint = {};
	std::stack<short> temp_short = {};
	std::stack<unsigned short> temp_ushort = {};
	std::stack<unsigned char> temp_uchar = {};
	std::stack<long> temp_long = {};
	std::stack<unsigned long> temp_ulong = {};

	////temp 2D vectors
	//std::stack<std::deque<int>> temp_2d_int;
	//std::stack<std::deque<double>> temp_2d_double;
	//std::stack<std::deque<char>> temp_2d_char;
	//std::stack<std::deque<bool>> temp_2d_bool;
	//std::stack<std::deque<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<stack_records> stack_records;

	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();

		stack_records.push_back({ stack_elements_num, type });
		switch (data_type) {
		case INT:
			temp_int = create_stack_int(stack_elements_num);
			oss += stack_to_string(temp_int);
			break;

		case FLOAT:
			temp_float = create_stack_float(stack_elements_num);
			oss += stack_to_string(temp_float);
			break;

		case DOUBLE:
			temp_double = create_stack_double(stack_elements_num);
			oss += stack_to_string(temp_double);
			break;

		case CHAR:
			temp_char = create_stack_char(stack_elements_num);
			oss += stack_to_string(temp_char);
			break;

		case BOOL:
			temp_bool = create_stack_bool(stack_elements_num);
			oss += stack_to_string(temp_bool);
			break;
		case UCHAR:
			temp_uchar = create_stack_uchar(stack_elements_num);
			oss += stack_to_string(temp_uchar);

			break;
		case USHORT:
			temp_ushort = create_stack_ushort(stack_elements_num);
			oss += stack_to_string(temp_ushort);

			break;
		case SHORT:
			temp_short = create_stack_short(stack_elements_num);
			oss += stack_to_string(temp_short);

			break;
		case UINT:
			temp_uint = create_stack_uint(stack_elements_num);
			oss += stack_to_string(temp_uint);

			break;
		case ULONG:
			temp_ulong = create_stack_ulong(stack_elements_num);
			oss += stack_to_string(temp_ulong);

			break;
		case LONG:
			temp_long = create_stack_long(stack_elements_num);
			oss += stack_to_string(temp_long);
			break;
		}



		//if (data_type == INT) {

		//	for (int i = 1; i <= stack_elements_num; i++) {
		//		oss += std::to_string(temp_int.top());
		//		temp_int.pop();
		//		if (i != stack_elements_num) {
		//			oss += ", "; // Add a separator between numbers
		//		}
		//	}

		//	temp_int = {};
		//}
		//else if (data_type == FLOAT) {
		//	for (int i = 1; i <= stack_elements_num; i++) {
		//		oss += std::to_string(temp_float.top());
		//		temp_float.pop();
		//		if (i != stack_elements_num) {
		//			oss += ", "; // Add a separator between numbers
		//		}
		//	}

		//	temp_float = {};
		//}


		//else if (data_type == DOUBLE) {
		//	for (int i = 1; i <= stack_elements_num; i++) {
		//		oss += std::to_string(temp_double.top());
		//		temp_double.pop();
		//		if (i != stack_elements_num) {
		//			oss += ", "; // Add a separator between numbers
		//		}
		//	}

		//	temp_double = {};
		//}

		//else if (data_type == CHAR) {
		//	for (int i = 1; i <= stack_elements_num; i++) {
		//		oss += std::to_string(temp_char.top());
		//		temp_char.pop();
		//		if (i != stack_elements_num) {
		//			oss += ", "; // Add a separator between numbers
		//		}
		//	}

		//	temp_char = {};
		//}

		//else if (data_type == BOOL) {
		//	for (int i = 1; i <= stack_elements_num; i++) {
		//		oss += std::to_string(temp_bool.top());
		//		temp_bool.pop();
		//		if (i != stack_elements_num) {
		//			oss += ", "; // Add a separator between numbers
		//		}
		//	}
		//	temp_bool = {};
		//}


		//print out secton

		code += "	std::stack<" + type + "> stack_" + std::to_string(n) + ";\n";
		code += "	for (auto n_" + std::to_string(n) + " : {" + oss + "}) {\n";
		code += "	stack_" + std::to_string(n) + ".push(n_"+ std::to_string(n) +");\n";
		code += "    }\n";
		oss = {};

	}

	//random operations generated
	auto stack_init = code;
	code.clear();
	auto output_record = stack_records;
	auto [temp_string, temp_records] = random_stack_op(index, stack_records);
	code += temp_string;
	stack_records = temp_records;

	code += random_stack_loop(index, stack_records, 1);
	//for (int m = 0; m < index; m++) {
	//	code += "	std::vector<" + stack_records[m].type + "> newstack_" + std::to_string(m) + "(stack_" + std::to_string(m) + ".begin(), stack_" + std::to_string(m) + ".end());\n";
	//	code += "	append_data(buffer, newstack_" + std::to_string(m) + ");\n";

	//}

	code += "\n";

	//for (const auto& record : deq_records) {
	//	std::cout << "Deque length: " << record.length
	//		<< ", Type: " << record.type << std::endl;
	//}


	code += "\n";
	return { stack_init, code, output_record };
}



