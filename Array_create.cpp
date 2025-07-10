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
#include "Array_create.h"
#include <sstream>




std::vector<int> create_ary_int(int length = 1) {
	std::vector<int> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;
		}
	}
	return temp;
}

std::vector<float> create_ary_float(int length = 1) {
	std::vector<float> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;

		case 3:
			temp.push_back(random_Float(-100, 100));
			break;
		}
	}
	return temp;
}

std::vector<double> create_ary_double(int length = 1) {
	std::vector<double> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 4)) {
		case 1:
			temp.push_back(random_Int(-100, 100));
			break;

		case 2:
			temp.push_back(random_Bool());
			break;

		case 3:
			temp.push_back(random_Float(-100, 100));
			break;

		case 4:
			temp.push_back(random_Double(-100, 100));
			break;
		}
	}
	return temp;
}

std::vector<char> create_ary_char(int length = 1) {
	std::vector<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::vector<bool> create_ary_bool(int length = 1) {
	std::vector<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}


struct array_records {
	int length;
	std::string type;
};


std::string random_deq_op(int n, std::vector<array_records> records) {
	std::string op;
	int operation_numbers = random_Int(5, 5);
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
		switch (random_Int(1, 29)) {
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

std::string create_array(int index) {
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

	//temp 2D vectors
	std::vector<std::vector<int>> temp_2d_int;
	std::vector<std::vector<double>> temp_2d_double;
	std::vector<std::vector<char>> temp_2d_char;
	std::vector<std::vector<bool>> temp_2d_bool;
	std::vector<std::vector<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<array_records> ary_records;

	enum aval_Type {
		INT,
		DOUBLE,
		CHAR,
		BOOL,
		FLOAT,
		INT_2D,
		DOUBLE_2D,
		CHAR_2D,
		BOOL_2D,
		FLOAT_2D,
		NONE
	};

	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		switch (random_Int(1, 5))
			/*switch (1)*/ {
		case 1:
			type = "int";
			data_type = INT;
			ary_records.push_back({ array_elements_num, type });
			break;
		case 2:
			type = "float";
			data_type = FLOAT;
			ary_records.push_back({ array_elements_num, type });
			break;
		case 3:
			type = "double";
			data_type = DOUBLE;
			ary_records.push_back({ array_elements_num, type });
			break;
		case 4:
			type = "char";
			data_type = CHAR;
			ary_records.push_back({ array_elements_num, type });
			break;
		case 5:
			type = "bool";
			data_type = BOOL;
			ary_records.push_back({ array_elements_num, type });
			break;

		case 6:
			type = "std::array<int, "+std::to_string(array_elements_num) + ">";
			data_type = INT_2D;
			ary_records.push_back({ array_rows, type });
			break;
		case 7:
			type = "std::array<float, " + std::to_string(array_elements_num) + ">";
			data_type = FLOAT_2D;
			ary_records.push_back({ array_rows, type });
			break;
		case 8:
			type = "std::array<double, " + std::to_string(array_elements_num) + ">";
			data_type = DOUBLE_2D;
			ary_records.push_back({ array_rows, type });
			break;
		case 9:
			type = "std::array<char, " + std::to_string(array_elements_num) + ">";
			data_type = CHAR_2D;
			ary_records.push_back({ array_rows, type });
			break;
		case 10:
			type = "std::array<bool, " + std::to_string(array_elements_num) + ">";
			data_type = BOOL_2D;
			ary_records.push_back({ array_rows, type });
			break;
		}


		//vec_records.push_back({ vec_elements_num, type });


		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= array_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_ary_int(array_elements_num);
					break;
				case FLOAT_2D: //float
					temp_float = create_ary_float(array_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_ary_double(array_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_ary_char(array_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_ary_bool(array_elements_num);
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
				temp_int = create_ary_int(array_elements_num);
				break;

			case FLOAT:
				temp_float = create_ary_float(array_elements_num);
				break;

			case DOUBLE:
				temp_double = create_ary_double(array_elements_num);
				break;

			case CHAR:
				temp_char = create_ary_char(array_elements_num);
				break;

			case BOOL:
				temp_bool = create_ary_bool(array_elements_num);
				break;

			}



			if (data_type == INT) {

				for (int i = 1; i <= array_elements_num; i++) {
					oss += std::to_string(temp_int[i - 1]);
					if (i != array_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_int = {};
			}
			else if (data_type == FLOAT) {
				for (int i = 1; i <= array_elements_num; i++) {
					oss += std::to_string(temp_float[i - 1]);
					if (i != array_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_float = {};
			}


			else if (data_type == DOUBLE) {
				for (int i = 1; i <= array_elements_num; i++) {
					oss += std::to_string(temp_double[i - 1]);
					if (i != array_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_double = {};
			}

			else if (data_type == CHAR) {
				for (int i = 1; i <= array_elements_num; i++) {
					oss += std::to_string(temp_char[i - 1]);
					if (i != array_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_char = {};
			}

			else {
				for (int i = 1; i <= array_elements_num; i++) {
					oss += std::to_string(temp_bool[i - 1]);
					if (i != array_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
				temp_bool = {};
			}


			//print out secton

			code += "	std::array<" + type + ","+std::to_string(array_elements_num) + "> ary_" + std::to_string(n) + " = {" + oss + "}; \n";
			oss = {};

		}

	}
	//random operations generated
	code += random_deq_op(index, ary_records);

	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + ary_records[m].type + "> newary_" + std::to_string(m) + "(ary_" + std::to_string(m) + ".begin(), ary_" + std::to_string(m) + ".end());\n";
		code += "	append_data(buffer, newary_" + std::to_string(m) + ");\n";

	}

	code += "\n";




	code += "\n";
	return code;
}