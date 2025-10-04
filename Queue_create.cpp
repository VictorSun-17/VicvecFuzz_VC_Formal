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

std::queue<int> create_que_int(int length = 1) {
	std::queue<int> temp;
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

std::queue<float> create_que_float(int length = 1) {
	std::queue<float> temp;
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

std::queue<double> create_que_double(int length = 1) {
	std::queue<double> temp;
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

std::queue<char> create_que_char(int length = 1) {
	std::queue<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Char());
	}
	return temp;
}
std::queue<bool> create_que_bool(int length = 1) {
	std::queue<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Bool());
	}
	return temp;
}
std::queue<unsigned int> create_que_uint(int length = 1) {
	std::queue<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UInt(0, 100));
	}
	return temp;
}

std::queue<short> create_que_short(int length = 1) {
	std::queue<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Short(-100, 100));
	}

	return temp;
}

std::queue<unsigned short> create_que_ushort(int length = 1) {
	std::queue<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UShort(0, 100));
	}

	return temp;
}

std::queue<unsigned char> create_que_uchar(int length = 1) {
	std::queue<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_UChar());
	}

	return temp;
}

std::queue<long> create_que_long(int length = 1) {
	std::queue<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_Long(-100, 100));
	}

	return temp;
}

std::queue<unsigned long> create_que_ulong(int length = 1) {
	std::queue<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push(random_ULong(0, 100));
	}

	return temp;
}

std::string generate_queue_element(std::string type) {
	std::string op;
	int que_elements_num = random_Int(5, 10);
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
	else if (type == "std::queue<int>") {
		std::queue<int> temp_int = create_que_int(que_elements_num);
		op += "{";
		for (int k = 1; k <= que_elements_num; k++) {
			op += std::to_string(temp_int.front());
			temp_int.pop();
			if (k != que_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		return op;
	}
	else if (type == "std::queue<float>") {
		std::queue<float> temp_float = create_que_float(que_elements_num);
		op += "{";
		for (int k = 1; k <= que_elements_num; k++) {
			op += std::to_string(temp_float.front());
			temp_float.pop();
			if (k != que_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		return op;
	}
	else if (type == "std::queue<double>") {
		std::queue<double> temp_double = create_que_double(que_elements_num);
		op += "{";
		for (int k = 1; k <= que_elements_num; k++) {
			op += std::to_string(temp_double.front());
			temp_double.pop();
			if (k != que_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		return op;
	}
	else if (type == "std::queue<char>") {
		std::queue<char> temp_char = create_que_char(que_elements_num);
		op += "{";
		for (int k = 1; k <= que_elements_num; k++) {
			op += std::to_string(temp_char.front());
			temp_char.pop();
			if (k != que_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		return op;
	}
	else if (type == "std::queue<bool>") {
		std::queue<bool> temp_bool = create_que_bool(que_elements_num);
		op += "{";
		for (int k = 1; k <= que_elements_num; k++) {
			op += std::to_string(temp_bool.front());
			temp_bool.pop();
			if (k != que_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		return op;
	}

}
std::vector<queue_records> merge_records_min_length(
	const std::vector<queue_records>& records1,
	const std::vector<queue_records>& records2
) {
	std::vector<queue_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		queue_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}


std::pair<std::string, std::vector<queue_records>> random_que_op(int n, std::vector<queue_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<queue_records> local_records = records;
	int random_size = random_Int(5, 100);

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 8)) {
		case 1:
			op += "	que_" + std::to_string(current) + ".push(" + generate_queue_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
			local_records[current].length += 1* loop_index;
			break;
		case 2:
			if (record_1.length != 0) {
				op += "	que_" + std::to_string(current) + ".pop();\n";
				local_records[current].length -= 1* loop_index;
			}
			break;
		case 3:
			op += "	que_" + std::to_string(current) + ".size();\n";
			break;

		case 4:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	que_" + std::to_string(current) + ".swap(que_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 5:
			op += "	que_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 6:
			if (record_1.length != 0) {
				op += "	que_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
			}
			break;
		case 7:
			if (record_1.length != 0) {
				op += "	que_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
			}
			break;
		case 8:

			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
				or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
				or record_1.type == "unsigned long") {
				op += "	que_" + std::to_string(current) + ".emplace(" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::queue<int>")
			{
				op += "	que_" + std::to_string(current) + ".emplace(std::queue<int>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::queue<float>")
				op += "	que_" + std::to_string(current) + ".emplace(std::queue<float>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<double>")
				op += "	que_" + std::to_string(current) + ".emplace(std::queue<double>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<char>")
				op += "	que_" + std::to_string(current) + ".emplace(std::queue<char>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<bool>")
				op += "	que_" + std::to_string(current) + ".emplace(std::queue<bool>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			local_records[current].length += 1* loop_index;
			break;



		}

	}
	records = local_records;
	return { op, records };
}

std::string random_que_loop(int number_of_index, std::vector<queue_records> vec_records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	//std::vector<vector_records> local_records = vec_records;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = vec_records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 14)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() > " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() < " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() <= " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() >= " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() == " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".front() != " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_que_op(number_of_index, vec_records, 1, for_loop_size);
		//		vec_records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_que_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_que_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_que_op(number_of_index, vec_records, 1, for_loop_size);
		//		vec_records = temp_records;
		//		op += temp_string;
		//		op += "	index_que_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		case 9:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() > " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 10:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() < " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 11:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() <= " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 12:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() >= " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 13:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() == " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 14:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (que_" + std::to_string(current) + ".back() != " + generate_queue_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_que_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}

std::tuple<std::string, std::string, std::vector<queue_records>> create_queue(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int que_elements_num = random_Int(5, 10);

	int que_rows = 2;// 1 for 1D vector
	//temp vectors
	std::queue<int> temp_int = {};
	std::queue<float> temp_float = {};
	std::queue<double> temp_double = {};
	std::queue<char> temp_char = {};
	std::queue<bool> temp_bool = {};
	std::queue<unsigned int> temp_uint = {};
	std::queue<short> temp_short = {};
	std::queue<unsigned short> temp_ushort = {};
	std::queue<unsigned char> temp_uchar = {};
	std::queue<long> temp_long = {};
	std::queue<unsigned long> temp_ulong = {};

	//temp 2D vectors
	std::queue<std::queue<int>> temp_2d_int;
	std::queue<std::queue<double>> temp_2d_double;
	std::queue<std::queue<char>> temp_2d_char;
	std::queue<std::queue<bool>> temp_2d_bool;
	std::queue<std::queue<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<queue_records> que_records;


	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();
		que_records.push_back({ que_elements_num, type });

		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= que_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_que_int(que_elements_num);
					break;
				case FLOAT_2D: //float
					temp_float = create_que_float(que_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_que_double(que_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_que_char(que_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_que_bool(que_elements_num);
					break;
				}


				if (data_type == INT_2D) {
					temp_2d_int.push(temp_int);
					for (int k = 1; k <= que_elements_num; k++) {
						oss += std::to_string(temp_int.front());
						temp_int.pop();
						if (k != que_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < que_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
				}
				else if (data_type == FLOAT_2D) {
					temp_2d_float.push(temp_float);
					for (int k = 1; k <= que_elements_num; k++) {
						oss += std::to_string(temp_float.front());
						temp_float.pop();
						if (k != que_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < que_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
				}
				else if (data_type == DOUBLE_2D) {
					temp_2d_double.push(temp_double);
					for (int k = 1; k <= que_elements_num; k++) {
						oss += std::to_string(temp_double.front());
						temp_float.pop();
						if (k != que_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < que_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
				}
				else if (data_type == CHAR_2D) {
					temp_2d_char.push(temp_char);
					for (int k = 1; k <= que_elements_num; k++) {
						oss += std::to_string(temp_char.front());
						temp_char.pop();
						if (k != que_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < que_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
				}
				else if (data_type == BOOL_2D) {
					temp_2d_bool.push(temp_bool);
					for (int k = 1; k <= que_elements_num; k++) {
						oss += std::to_string(temp_bool.front());
						temp_bool.pop();
						if (k != que_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < que_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
				}


			}

			code += "	std::queue<" + type + "> que_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		}

		else {
				switch (data_type) {
				case INT:
					temp_int = create_que_int(que_elements_num);
					oss += queue_to_string(temp_int);

					temp_int = {};
					break;

				case FLOAT:
					temp_float = create_que_float(que_elements_num);
					oss += queue_to_string(temp_float);

					temp_float = {};
					break;

				case DOUBLE:
					temp_double = create_que_double(que_elements_num);
					oss += queue_to_string(temp_double);

					temp_double = {};
					break;

				case CHAR:
					temp_char = create_que_char(que_elements_num);
					oss += queue_to_string(temp_char);

					temp_char = {};
					break;

				case BOOL:
					temp_bool = create_que_bool(que_elements_num);
					oss += queue_to_string(temp_bool);
					temp_bool = {};
					break;
				case UCHAR:
					temp_uchar = create_que_uchar(que_elements_num);
					oss += queue_to_string(temp_uchar);
					temp_uchar = {};
					break;
				case USHORT:
					temp_ushort = create_que_ushort(que_elements_num);
					oss += queue_to_string(temp_ushort);
					temp_ushort = {};
					break;
				case SHORT:
					temp_short = create_que_short(que_elements_num);
					oss += queue_to_string(temp_short);
					temp_short = {};
					break;
				case UINT:
					temp_uint = create_que_uint(que_elements_num);
					oss += queue_to_string(temp_uint);
					temp_uint = {};
					break;
				case ULONG:
					temp_ulong = create_que_ulong(que_elements_num);
					oss += queue_to_string(temp_ulong);
					temp_ulong = {};
					break;
				case LONG:
					temp_long = create_que_long(que_elements_num);
					oss += queue_to_string(temp_long);
					temp_long = {};
					break;

				}


			//print out secton
			switch (random_Int(1, 2)) {
			case 1:
				code += "	std::queue<" + type + "> que_" + std::to_string(n) + ";\n";
				code += "	for (" + type + " q_" + std::to_string(n) + " : {" + oss + "}) {\n";
				code += "	que_" + std::to_string(n) + ".push(q_" + std::to_string(n) + ");\n";
				code += "	}\n";
				break;
			case 2:
				code += "	std::deque<" + type + "> deque_to_queue_" + std::to_string(n) + " = {" + oss + "};\n";
				code += "	std::queue<" + type + "> que_" + std::to_string(n) + "(deque_to_queue_" + std::to_string(n) + ");\n";
				break;
			}
			oss = {};



		}

	}
	auto que_init = code;
	code.clear();
	auto output_record = que_records;
	//random operations generated
	auto [temp_string, temp_records] = random_que_op(index, que_records);
	code += temp_string;
	que_records = temp_records;

	code += random_que_loop(index, que_records,1);

	code += "\n";
	return { que_init, code, output_record };
}
