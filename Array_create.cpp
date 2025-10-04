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


std::string generate_array_element(std::string type) {
	std::string op;
	int vec_elements_num = random_Int(5, 10);
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


std::string arithmatic_block(int n, std::vector<array_records> records, int operation_numbers = 3) {
	std::string oss;
	int current = 0;
	int current_2 = 0;
	std::vector<array_records> local_records = records;
	for (int m = 1; m <= operation_numbers; m++) {
		current = randomInt(0, n - 1);
		current_2 = randomInt(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		switch (random_Int(1, 6)) {
		case 1:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::plus()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_array_element(record_1.type) + "); \n";
			break;
		case 2:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::minus()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_array_element(record_1.type) + "); \n";
			break;
		case 3:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::multiplies()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_array_element(record_1.type) + "); \n";
			break;
		case 4:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::divides()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_array_element(record_1.type) + "); \n";
			break;
		case 5:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::modulus()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_array_element(record_1.type) + "); \n";
			break;
		case 6:
			oss += "	auto arith_ary_" + std::to_string(m) + " = std::negate()(ary_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "] ); \n";
			break;

		}

	}
	return oss;
}


std::string random_array_op(int n, std::vector<array_records> records, int operation_numbers = random_Int(5, 5)) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<array_records> local_records = records;
	int random_size = random_Int(5, 100);

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 16)) {
		case 1:
			op += "	ary_" + std::to_string(current) + ".size();\n";
			break;
		case 2:
			op += "	ary_" + std::to_string(current) + ".max_size();\n";
			break;
		case 3:
			op += "	ary_" + std::to_string(current) + ".empty();\n";
			break;
		case 4:
				op += "	ary_" + std::to_string(current) + ".at(" + std::to_string(random_Int(0, record_1.length - 1)) + ");\n";
			break;
		case 5:
				op += "	ary_" + std::to_string(current) + ".front();\n";
			break;
		case 6:
				op += "	ary_" + std::to_string(current) + ".back();\n";
			break;
		case 7:
			op += "	ary_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 8:
			op += "	ary_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 9:
			op += "	ary_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 10:
			op += "	ary_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 11:
			op += "	ary_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 12:
			op += "	ary_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 13:
			op += "	ary_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 14:
			op += "	ary_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;
		case 15:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	ary_" + std::to_string(current) + ".swap(ary_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 16:
			if (record_1.type == "int") {
					op += "	ary_" + std::to_string(current) + ".fill(" + std::to_string(random_Int(-100, 100))+"); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "float") {
				op += "	ary_" + std::to_string(current) + ".fill(" + std::to_string(random_Float(-100, 100)) +"); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "double") {
				op += "	ary_" + std::to_string(current) + ".fill(" + std::to_string(random_Double(-100, 100)) +"); \n"; // Constructs and inserts an element in the vector.

			}
			else if (record_1.type == "char") {
				op += "	ary_" + std::to_string(current) + ".fill(" + std::to_string(random_Char()) +"); \n"; // Constructs and inserts an element in the vector.

			}
			else if (record_1.type == "bool") {
				op += "	ary_" + std::to_string(current) + ".fill(" + std::to_string(random_Bool()) +"); \n"; // Constructs and inserts an element in the vector.

			}
			break;

		}

	}




	return op;
}


std::string random_array_loop(int number_of_index, std::vector<array_records> vec_records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	//std::vector<vector_records> local_records = vec_records;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = vec_records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] > " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] < " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] <= " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] >= " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] == " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (ary_" + std::to_string(current) + "[" + std::to_string(idx) + "] != " + generate_array_element(record_1.type) + ") {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
				op += "	else {\n";
				op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_ary_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_ary_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		op += random_array_op(number_of_index, vec_records, random_Int(0, 5));
		//		op += "	index_ary_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}






std::tuple<std::string, std::string, std::vector<array_records>> create_array(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int array_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int array_rows = 1;// 1 for 1D vector
	//temp vectors
	std::vector<int> temp_int = {};
	std::vector<float> temp_float = {};
	std::vector<double> temp_double = {};
	std::vector<char> temp_char = {};
	std::vector<bool> temp_bool = {};
	std::vector<unsigned int> temp_uint = {};
	std::vector<short> temp_short = {};
	std::vector<unsigned short> temp_ushort = {};
	std::vector<unsigned char> temp_uchar = {};
	std::vector<long> temp_long = {};
	std::vector<unsigned long> temp_ulong = {};

	//temp 2D vectors
	std::vector<std::vector<int>> temp_2d_int;
	std::vector<std::vector<double>> temp_2d_double;
	std::vector<std::vector<char>> temp_2d_char;
	std::vector<std::vector<bool>> temp_2d_bool;
	std::vector<std::vector<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<array_records> ary_records;

	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();

		ary_records.push_back({ array_elements_num, type });
		//vec_records.push_back({ vec_elements_num, type });


		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= array_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_vec_int(array_elements_num);
					break;
				case FLOAT_2D: //float
					temp_float = create_vec_float(array_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_vec_double(array_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_vec_char(array_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_vec_bool(array_elements_num);
					break;
				}


				if (data_type == INT_2D) {
					temp_2d_int.push_back(temp_int);
					for (int k = 1; k <= array_elements_num; k++) {
						oss += std::to_string(temp_int[k - 1]);
						if (k != array_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < array_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_int.clear();
				}
				else if (data_type == FLOAT_2D) {
					temp_2d_float.push_back(temp_float);
					for (int k = 1; k <= array_elements_num; k++) {
						oss += std::to_string(temp_float[k - 1]);
						if (k != array_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < array_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_float.clear();
				}
				else if (data_type == DOUBLE_2D) {
					temp_2d_double.push_back(temp_double);
					for (int k = 1; k <= array_elements_num; k++) {
						oss += std::to_string(temp_double[k - 1]);
						if (k != array_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < array_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_double.clear();
				}
				else if (data_type == CHAR_2D) {
					temp_2d_char.push_back(temp_char);
					for (int k = 1; k <= array_elements_num; k++) {
						oss += std::to_string(temp_char[k - 1]);
						if (k != array_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < array_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_char.clear();
				}
				else if (data_type == BOOL_2D) {
					temp_2d_bool.push_back(temp_bool);
					for (int k = 1; k <= array_elements_num; k++) {
						oss += std::to_string(temp_bool[k - 1]);
						if (k != array_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < array_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool.clear();
				}


			}

			code += "	std::array<" + type + ","+ std::to_string(array_rows) +"> ary_" + std::to_string(n) + " = {{" + oss + "}; \n";
			oss = {};
		}

		else {
			switch (data_type) {
			case INT:
				temp_int = create_vec_int(array_elements_num);
				oss += vector_to_string(temp_int);

				temp_int = {};
				break;

			case FLOAT:
				temp_float = create_vec_float(array_elements_num);
				oss += vector_to_string(temp_float);

				temp_float = {};
				break;

			case DOUBLE:
				temp_double = create_vec_double(array_elements_num);
				oss += vector_to_string(temp_double);

				temp_double = {};
				break;

			case CHAR:
				temp_char = create_vec_char(array_elements_num);
				oss += vector_to_string(temp_char);

				temp_char = {};
				break;

			case BOOL:
				temp_bool = create_vec_bool(array_elements_num);
				oss += vector_to_string(temp_bool);
				temp_bool = {};
				break;
			case UCHAR:
				temp_uchar = create_vec_uchar(array_elements_num);
				oss += vector_to_string(temp_uchar);
				temp_uchar = {};
				break;
			case USHORT:
				temp_ushort = create_vec_ushort(array_elements_num);
				oss += vector_to_string(temp_ushort);
				temp_ushort = {};
				break;
			case SHORT:
				temp_short = create_vec_short(array_elements_num);
				oss += vector_to_string(temp_short);
				temp_short = {};
				break;
			case UINT:
				temp_uint = create_vec_uint(array_elements_num);
				oss += vector_to_string(temp_uint);
				temp_uint = {};
				break;
			case ULONG:
				temp_ulong = create_vec_ulong(array_elements_num);
				oss += vector_to_string(temp_ulong);
				temp_ulong = {};
				break;
			case LONG:
				temp_long = create_vec_long(array_elements_num);
				oss += vector_to_string(temp_long);
				temp_long = {};
				break;

			}
			//print out secton
			switch (random_Int(1, 2)) {
			case 1:
				code += "	std::array<" + type + "," + std::to_string(array_elements_num) + "> ary_" + std::to_string(n) + " = {" + oss + "}; \n";
				break;
			case 2:
				code += "	std::array<" + type + "," + std::to_string(array_elements_num) + "> ary_" + std::to_string(n) + " {" + oss + "}; \n";
			}
			oss = {};

		}

	}
	auto array_init = code;
	code = {};
	//random operations generated
	code += random_array_op(index, ary_records);
	code += random_array_loop(index, ary_records,1);

	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + ary_records[m].type + "> newary_" + std::to_string(m) + "(ary_" + std::to_string(m) + ".begin(), ary_" + std::to_string(m) + ".end());\n";
		code += "	append_data(buffer, newary_" + std::to_string(m) + ");\n";

	}

	code += "\n";




	code += "\n";
	return { array_init,code,ary_records};
}