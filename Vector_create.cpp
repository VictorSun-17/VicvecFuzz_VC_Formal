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
#include "Vector_create.h"
#include <sstream>


int randomInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

int random_Int(int min, int max) {
	return min + rand() % (max - min + 1);
}

// Function to generate a random float in a given range
float random_Float(float min, float max) {
	return min + static_cast<float>(rand()) / RAND_MAX * (max - min);
}

// Function to generate a random double in a given range
double random_Double(double min, double max) {
	return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

// Function to generate a random character (A-Z, a-z, 0-9)
char random_Char() {
	const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int generated_char = rand() % (sizeof(charset) - 1); // Exclude null terminator
	return charset[generated_char];
}

// Function to generate a random boolean value
bool random_Bool() {
	return rand() % 2; // Returns either 0 (false) or 1 (true)
}

std::vector<int> create_vec_int(int length = 1) {
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

std::vector<float> create_vec_float(int length = 1) {
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

std::vector<double> create_vec_double(int length = 1) {
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

std::vector<char> create_vec_char(int length = 1) {
	std::vector<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::vector<bool> create_vec_bool(int length = 1) {
	std::vector<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}

struct vector_records {
	int length;
	std::string type;
};

std::string generate_element(std::string type) {
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
	else if (type == "std::vector<int>") {
		std::vector<int> temp_int = create_vec_int(vec_elements_num);
		op += "{";
		for (int k = 1; k <= vec_elements_num; k++) {
			op += std::to_string(temp_int[k - 1]);
			if (k != vec_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_int.clear();
		return op;
	}
	else if (type == "std::vector<float>") {
		std::vector<float> temp_float = create_vec_float(vec_elements_num);
		op += "{";
		for (int k = 1; k <= vec_elements_num; k++) {
			op += std::to_string(temp_float[k - 1]);
			if (k != vec_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_float.clear();
		return op;
	}
	else if (type == "std::vector<double>") {
		std::vector<double> temp_double = create_vec_double(vec_elements_num);
		op += "{";
		for (int k = 1; k <= vec_elements_num; k++) {
			op += std::to_string(temp_double[k - 1]);
			if (k != vec_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_double.clear();
		return op;
	}
	else if (type == "std::vector<char>") {
		std::vector<char> temp_char = create_vec_char(vec_elements_num);
		op += "{";
		for (int k = 1; k <= vec_elements_num; k++) {
			op += std::to_string(temp_char[k - 1]);
			if (k != vec_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_char.clear();
		return op;
	}
	else if (type == "std::vector<bool>") {
		std::vector<bool> temp_bool = create_vec_bool(vec_elements_num);
		op += "{";
		for (int k = 1; k <= vec_elements_num; k++) {
			op += std::to_string(temp_bool[k - 1]);
			if (k != vec_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_bool.clear();
		return op;
	}

}



std::string random_vec_op(int n, std::vector<vector_records> vec_records) {
	std::string op;
	int operation_numbers = randomInt(5, 5);
	int current = 0;
	int current_2 = 0;
	std::vector<vector_records> local_records = vec_records;
	int random_size = randomInt(1, 20);

	//移出所有已生成函数的rdm

	for (int m = 1; m <= operation_numbers; m++) {
		current = randomInt(0, n - 1);
		current_2 = randomInt(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (randomInt(1, 30)) {
		case 1:
			op += "	vec_" + std::to_string(current) + ".push_back(" + generate_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
			local_records[current].length += 1;
			break;
		case 2:
			if (record_1.length == 0) {
				op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin()," + generate_element(record_1.type) + "); \n"; //insert at certain place
			}
			else {
				op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "," + generate_element(record_1.type) + "); \n"; //insert at certain place
			}
			local_records[current].length += 1;
			break;
		case 3:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".erase(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1))+ "); \n";
				local_records[current].length -= 1;
			}
			break;
		case 4:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".pop_back();\n";
				local_records[current].length -= 1;
			}
			break;
		case 5:
			op += "	vec_" + std::to_string(current) + ".resize(" + std::to_string(random_size) + ","+ generate_element(record_1.type) + ");\n";
			local_records[current].length = random_size;
			break;
		case 6:
			//op += "	std::reverse(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
			break;
		case 7:
			//tried in jasper, take forever 
			//op += "	std::sort(vec_" + std::to_string(current) + ".begin(), vec_" + std::to_string(current) + ".end());\n";
			break;
		case 8:
			op += "	vec_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;
		case 9:
			op += "	vec_" + std::to_string(current) + ".assign(static_cast<size_t> (" + std::to_string(random_size)+"), " + generate_element(record_1.type) + ");\n";
			break;
		case 10:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduce capacity to fit size
			break;
		case 11:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	vec_" + std::to_string(current) + ".swap(vec_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 12:
			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
				op += "	vec_" + std::to_string(current) + ".emplace_back(" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			}
			else if (record_1.type == "std::vector<int>")
				op += "	vec_" + std::to_string(current) + ".emplace_back(std::initializer_list<int>" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			else if (record_1.type == "std::vector<float>")
				op += "	vec_" + std::to_string(current) + ".emplace_back(std::initializer_list<float>" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			else if (record_1.type == "std::vector<double>")
				op += "	vec_" + std::to_string(current) + ".emplace_back(std::initializer_list<double>" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			else if (record_1.type == "std::vector<char>")
				op += "	vec_" + std::to_string(current) + ".emplace_back(std::initializer_list<char>" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			else if (record_1.type == "std::vector<bool>")
				op += "	vec_" + std::to_string(current) + ".emplace_back(std::initializer_list<bool>" + generate_element(record_1.type) + ");\n"; // Efficient push_back
			local_records[current].length += 1;
			break;
		case 13:
			op += "	vec_" + std::to_string(current) + ".capacity();\n"; // Print capacity
			break;
		case 14:
			op += "	vec_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 15:
			op += "	vec_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;
		case 16:
			op += "	vec_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 17:
			if (record_1.length != 0) {
			op += "	vec_" + std::to_string(current) + ".at("+ std::to_string(random_Int(0, record_1.length - 1)) +"); \n"; //Accesses the element at a specific position, with bounds checking.
			}
			break;
		case 18:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
			}
			break;
		case 19:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
			}
			break;
		case 20:
			op += "	vec_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 21:
			op += "	vec_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 22:
			op += "	vec_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 23:
			op += "	vec_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 24:
			op += "	vec_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 25:
			op += "	vec_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 26:
			op += "	vec_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 27:
			op += "	vec_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;
		case 28:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduces memory usage by freeing unused space.
			break;

		case 29:

			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + "+ std::to_string(random_Int(0, record_1.length - 1)) +") ," + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::vector<int>")
			{
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<int>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			}
			else if (record_1.type == "std::vector<float>")
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<float>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::vector<double>")
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::initializer_list<double>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if (record_1.type == "std::vector<char>")
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::initializer_list<char>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			else if(record_1.type == "std::vector<bool>")
				op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::initializer_list<bool>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
			local_records[current].length += 1;
			break;
		case 30:
			op += "	vec_" + std::to_string(current) + ".reserve(" + std::to_string(randomInt(1, 10000)) + "); \n"; // Requests that the vector capacity be at least enough to contain a specified number of elements.
			break;



		}

	}




	return op;
}



std::string create_vec(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int vec_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int vec_rows = 2;// 1 for 1D vector
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

	std::vector<vector_records> vec_records;

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
			vec_records.push_back({ vec_elements_num, type });
			break;
		case 2:
			type = "float";
			data_type = FLOAT;
			vec_records.push_back({ vec_elements_num, type });
			break;
		case 3:
			type = "double";
			data_type = DOUBLE;
			vec_records.push_back({ vec_elements_num, type });
			break;
		case 4:
			type = "char";
			data_type = CHAR;
			vec_records.push_back({ vec_elements_num, type });
			break;
		case 5:
			type = "bool";
			data_type = BOOL;
			vec_records.push_back({ vec_elements_num, type });
			break;

		case 6:
			type = "std::vector<int>";
			data_type = INT_2D;
			vec_records.push_back({ vec_rows, type });
			break;
		case 7:
			type = "std::vector<float>";
			data_type = FLOAT_2D;
			vec_records.push_back({ vec_rows, type });
			break;
		case 8:
			type = "std::vector<double>";
			data_type = DOUBLE_2D;
			vec_records.push_back({ vec_rows, type });
			break;
		case 9:
			type = "std::vector<char>";
			data_type = CHAR_2D;
			vec_records.push_back({ vec_rows, type });
			break;
		case 10:
			type = "std::vector<bool>";
			data_type = BOOL_2D;
			vec_records.push_back({ vec_rows, type });
			break;
		}


		//vec_records.push_back({ vec_elements_num, type });


		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= vec_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_vec_int(vec_elements_num);
					break;
				case FLOAT_2D: //float
					temp_float = create_vec_float(vec_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_vec_double(vec_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_vec_char(vec_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_vec_bool(vec_elements_num);
					break;
				}


				if (data_type == INT_2D) {
					temp_2d_int.push_back(temp_int);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_int[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_int.clear();
				}
				else if (data_type == FLOAT_2D) {
					temp_2d_float.push_back(temp_float);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_float[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_float.clear();
				}
				else if (data_type == DOUBLE_2D) {
					temp_2d_double.push_back(temp_double);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_double[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_double.clear();
				}
				else if (data_type == CHAR_2D) {
					temp_2d_char.push_back(temp_char);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_char[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_char.clear();
				}
				else if (data_type == BOOL_2D) {
					temp_2d_bool.push_back(temp_bool);
					for (int k = 1; k <= vec_elements_num; k++) {
						oss += std::to_string(temp_bool[k - 1]);
						if (k != vec_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < vec_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool.clear();
				}


			}
			//for (const auto& row : temp_2d_int) {
			//	for (const auto& val : row) {
			//		std::cout << val << " ";
			//	}
			//	std::cout << std::endl;
			//}

			code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		}

		else {
			switch (data_type) {
			case INT:
				temp_int = create_vec_int(vec_elements_num);
				break;

			case FLOAT:
				temp_float = create_vec_float(vec_elements_num);
				break;

			case DOUBLE:
				temp_double = create_vec_double(vec_elements_num);
				break;

			case CHAR:
				temp_char = create_vec_char(vec_elements_num);
				break;

			case BOOL:
				temp_bool = create_vec_bool(vec_elements_num);
				break;

			}



			if (data_type == INT) {

				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_int[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_int = {};
			}
			else if (data_type == FLOAT) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_float[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_float = {};
			}


			else if (data_type == DOUBLE) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_double[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_double = {};
			}

			else if (data_type == CHAR) {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_char[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_char = {};
			}

			else {
				for (int i = 1; i <= vec_elements_num; i++) {
					oss += std::to_string(temp_bool[i - 1]);
					if (i != vec_elements_num) {
						oss += ", "; // Add a separator between numbers
					}
				}
				temp_bool = {};
			}


			//print out secton

			code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = {" + oss + "};\n";
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
	code += random_vec_op(index, vec_records);

	code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	append_data(buffer, vec_" + std::to_string(m) + ");\n";

	}




	code += "\n";
	return code;
}
