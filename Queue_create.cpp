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
#include "Queue_create.h"
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

struct queue_records {
	int length;
	std::string type;
};

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



std::string random_que_op(int n, std::vector<queue_records> records) {
	std::string op;
	int operation_numbers = random_Int(5, 5);
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
			local_records[current].length += 1;
			break;
		case 2:
			if (record_1.length != 0) {
				op += "	que_" + std::to_string(current) + ".pop();\n";
				local_records[current].length -= 1;
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

			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
				op += "	vec_" + std::to_string(current) + ".emplace(" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::queue<int>")
			{
				op += "	vec_" + std::to_string(current) + ".emplace(std::queue<int>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::queue<float>")
				op += "	vec_" + std::to_string(current) + ".emplace(std::queue<float>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<double>")
				op += "	vec_" + std::to_string(current) + ".emplace(std::queue<double>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<char>")
				op += "	vec_" + std::to_string(current) + ".emplace(std::queue<char>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::queue<bool>")
				op += "	vec_" + std::to_string(current) + ".emplace(std::queue<bool>" + generate_queue_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			local_records[current].length += 1;
			break;



		}

	}
	return op;
}


std::string create_queue(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int que_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int que_rows = 2;// 1 for 1D vector
	//temp vectors
	std::queue<int> temp_int = {};
	std::queue<float> temp_float = {};
	std::queue<double> temp_double = {};
	std::queue<char> temp_char = {};
	std::queue<bool> temp_bool = {};

	//temp 2D vectors
	std::queue<std::queue<int>> temp_2d_int;
	std::queue<std::queue<double>> temp_2d_double;
	std::queue<std::queue<char>> temp_2d_char;
	std::queue<std::queue<bool>> temp_2d_bool;
	std::queue<std::queue<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<queue_records> que_records;

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
			que_records.push_back({ que_elements_num, type });

			break;
		case 2:
			type = "float";
			data_type = FLOAT;
			que_records.push_back({ que_elements_num, type });
			break;
		case 3:
			type = "double";
			data_type = DOUBLE;
			que_records.push_back({ que_elements_num, type });
			break;
		case 4:
			type = "char";
			data_type = CHAR;
			que_records.push_back({ que_elements_num, type });
			break;
		case 5:
			type = "bool";
			data_type = BOOL;
			que_records.push_back({ que_elements_num, type });
			break;

		case 6:
			type = "std::queue<int>";
			data_type = INT_2D;
			que_records.push_back({ que_rows, type });
			break;
		case 7:
			type = "std::queue<float>";
			data_type = FLOAT_2D;
			que_records.push_back({ que_rows, type });
			break;
		case 8:
			type = "std::queue<double>";
			data_type = DOUBLE_2D;
			que_records.push_back({ que_rows, type });
			break;
		case 9:
			type = "std::queue<char>";
			data_type = CHAR_2D;
			que_records.push_back({ que_rows, type });
			break;
		case 10:
			type = "std::queue<bool>";
			data_type = BOOL_2D;
			que_records.push_back({ que_rows, type });
			break;
		}


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
			//for (const auto& row : temp_2d_int) {
			//	for (const auto& val : row) {
			//		std::cout << val << " ";
			//	}
			//	std::cout << std::endl;
			//}

			code += "	std::queue<" + type + "> que_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		}

		else {
			switch (data_type) {
			case INT:
				temp_int = create_que_int(que_elements_num);
				break;

			case FLOAT:
				temp_float = create_que_float(que_elements_num);
				break;

			case DOUBLE:
				temp_double = create_que_double(que_elements_num);
				break;

			case CHAR:
				temp_char = create_que_char(que_elements_num);
				break;

			case BOOL:
				temp_bool = create_que_bool(que_elements_num);
				break;

			}



			if (data_type == INT) {

				for (int i = 1; i <= que_elements_num; i++) {
					oss += std::to_string(temp_int.front());
					temp_int.pop();
					if (i != que_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
			}
			else if (data_type == FLOAT) {
				for (int i = 1; i <= que_elements_num; i++) {
					oss += std::to_string(temp_float.front());
					temp_float.pop();
					if (i != que_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
			}


			else if (data_type == DOUBLE) {
				for (int i = 1; i <= que_elements_num; i++) {
					oss += std::to_string(temp_double.front());
					temp_double.pop();
					if (i != que_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

			}

			else if (data_type == CHAR) {
				for (int i = 1; i <= que_elements_num; i++) {
					oss += std::to_string(temp_char.front());
					temp_char.pop();
					if (i != que_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

			}

			else {
				for (int i = 1; i <= que_elements_num; i++) {
					oss += std::to_string(temp_bool.front());
					temp_bool.pop();
					if (i != que_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
			}


			//print out secton

			code += "	std::queue<" + type + "> que_" + std::to_string(n) + " = {" + oss + "};\n";
			oss = {};

			//This is about print out each vector
			/*if (data_type == INT) {

				code += "for (int num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else if (data_type == FLOAT) {
				code += "for (float num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}


			else if (data_type == DOUBLE) {
				code += "for (double num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else if (data_type == CHAR) {
				code += "for (char num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}

			else {
				code += "for (bool num : vec_" + std::to_string(n) + ") { \n";

				code += "	std::cout << num << ' ';\n";

				code += "	std::cout << std::endl;\n";
				code += "}\n";
			}*/



		}

	}
	//random operations generated
	code += random_que_op(index, que_records);


	code += "\n";
	return code;
}
