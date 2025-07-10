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
#include "Set_create.h"


std::set<int> create_set_int(int length = 1) {
	std::set<int> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;
		}
	}
	return temp;
}

std::set<float> create_set_float(int length = 1) {
	std::set<float> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 2)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;

		case 3:
			temp.emplace(random_Float(-100, 100));
			break;
		}
	}
	return temp;
}

std::set<double> create_set_double(int length = 1) {
	std::set<double> temp;
	for (int n = 1; n <= length; n++) {
		switch (random_Int(1, 4)) {
		case 1:
			temp.emplace(random_Int(-100, 100));
			break;

		case 2:
			temp.emplace(random_Bool());
			break;

		case 3:
			temp.emplace(random_Float(-100, 100));
			break;

		case 4:
			temp.emplace(random_Double(-100, 100));
			break;
		}
	}
	return temp;
}

std::set<char> create_set_char(int length = 1) {
	std::set<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Char());
	}
	return temp;
}

std::set<bool> create_set_bool(int length = 1) {
	std::set<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Bool());
	}
	return temp;
}


struct set_records {
	int length;
	std::string type;
};

std::string generate_set_element(std::string type) {
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
	else if (type == "std::set<int>") {
		std::set<int> temp_int = create_set_int(vec_elements_num);
		op += "{";
		int temp_size = temp_int.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_int.begin();
			advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_int.clear();
		return op;
	}
	else if (type == "std::set<float>") {
		std::set<float> temp_float = create_set_float(vec_elements_num);
		op += "{";
		int temp_size = temp_float.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_float.begin();
			advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_float.clear();
		return op;
	}
	else if (type == "std::set<double>") {
		std::set<double> temp_double = create_set_double(vec_elements_num);
		op += "{";
		int temp_size = temp_double.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_double.begin();
			advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_double.clear();
		return op;
	}
	else if (type == "std::set<char>") {
		std::set<char> temp_char = create_set_char(vec_elements_num);
		op += "{";
		int temp_size = temp_char.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_char.begin();
			advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_char.clear();
		return op;
	}
	else if (type == "std::set<bool>") {
		std::set<bool> temp_bool = create_set_bool(vec_elements_num);
		op += "{";
		int temp_size = temp_bool.size();
		for (int k = 1; k <= temp_size; k++) {
			auto it = temp_bool.begin();
			advance(it, k - 1);
			auto value = *it;
			op += std::to_string(value);
			if (k != temp_size) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_bool.clear();
		return op;
	}

}



std::string random_set_op(int n, std::vector<set_records> records) {
	std::string op;
	int operation_numbers = random_Int(5, 5);
	int current = 0;
	int current_2 = 0;
	std::vector<set_records> local_records = records;
	int random_size = random_Int(5, 100);
	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 24)) {
		case 1:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".begin(); \n";//An iterator to the first element in the container.
			}
			break;
		case 2:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".cbegin(); \n";//A const_iterator to the beginning of the sequence.
			}
			break;
		case 3:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".cend(); \n";//A const_iterator to the element past the end of the sequence.
			}
			break;
		case 4:
			op += "set_" + std::to_string(current) + ".clear(); \n";//clean all
			local_records[current].length = 0;
			break;
		case 5:
			op += "set_" + std::to_string(current) + ".count(" + generate_set_element(record_1.type) + "); \n";//A const_iterator to the element past the end of the sequence.
			break;
		case 6:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".crbegin(); \n";//A const_reverse_iterator to the reverse beginning of the sequence.
			}
			break;
		case 7:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".crend(); \n";//A const_reverse_iterator to the reverse end of the sequence.
			}
			break;
		case 8:
			//TODO:need optimization
			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
				op += "set_" + std::to_string(current) + ".emplace(" + generate_set_element(record_1.type) + "); \n";
			}
			else if (record_1.type == "std::vector<int>") 
				op += "set_" + std::to_string(current) + ".emplace(std::set<int>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<float>")
				op += "set_" + std::to_string(current) + ".emplace(std::set<float>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<double>")
				op += "set_" + std::to_string(current) + ".emplace(std::set<double>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<char>")
				op += "set_" + std::to_string(current) + ".emplace(std::set<char>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<bool>")
				op += "set_" + std::to_string(current) + ".emplace(std::set<bool>" + generate_set_element(record_1.type) + "); \n";
			// If the function successfully inserts the element(because no equivalent element existed already in the set), 
			// the function returns a pair of an iterator to the newly inserted element and a value of true.
			if (record_1.type != "bool") {
				local_records[current].length += 1;
				}
			break;
		case 9:
			//TODO: need optimization
			//op += "set_" + std::to_string(current) + ".emplace_hint(set_" + std::to_string(current) + ".find(" + std::to_string(random_Int(1, 100)) + ")," + std::to_string(random_Int(1, 100)) + "); \n";
			break;
		case 10:
			op += "set_" + std::to_string(current) + ".empty(); \n";//true if the container size is 0, false otherwise.
			break;
		case 11:
			if (record_1.length != 0) {
				op += "set_" + std::to_string(current) + ".end(); \n";//An iterator to the past-the-end element in the container.
			}
			break;
		case 12:
			op += "auto range_" + std::to_string(m) + " = set_" + std::to_string(current) + ".equal_range(" + generate_set_element(record_1.type) + "); \n";
			//The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			break;
		case 13:
			if (record_1.length != 0) {
				op += "auto it_"+std::to_string(m) + " = next(set_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "set_" + std::to_string(current) + ".erase(it_" + std::to_string(m) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
				local_records[current].length -= 1;
			}
			break;
		case 14:
			op += "auto it_" + std::to_string(m) + " = set_" + std::to_string(current) + ".find(" + generate_set_element(record_1.type) + ");\n"; //An iterator to the element, if val is found, or set::end otherwise.
			break;
		case 15:
			op += "auto alloc_" + std::to_string(m) + " = set_" + std::to_string(current) + ".get_allocator();\n";//Member type allocator_type is the type of the allocator used by the container, defined in set as an alias of its third template parameter
			break;
		case 16:
			op += "set_" + std::to_string(current) + ".insert(" + generate_set_element(record_1.type) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
			if (record_1.type != "std::vector<bool>" or record_1.type != "bool") {
				local_records[current].length += 1;
			}
			break;
		case 17:
			op += "auto mycomp_" + std::to_string(m) + " = set_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
			break;
		case 18:
			op += "auto itlow_" + std::to_string(m) + " = set_" + std::to_string(current) + ".lower_bound(" + generate_set_element(record_1.type) + ");\n";
			//Returns an iterator pointing to the first element in the container which is not considered to go before val (i.e., either it is equivalent or goes after).
			break;
		case 19:
			op += "set_" + std::to_string(current) + ".max_size();\n"; //The maximum number of elements a set container can hold as content.
			break;
		case 20:
			op += "set_" + std::to_string(current) + ".rbegin();\n"; //A reverse iterator to the reverse beginning of the sequence container.
			break;
		case 21:
			op += "set_" + std::to_string(current) + ".rend();\n"; //A reverse iterator to the reverse end of the sequence container.
			break;
		case 22:
			op += "set_" + std::to_string(current) + ".size();\n"; //The number of elements in the container.
			break;
		case 23:
			if (record_1.type == record_2.type && current != current_2) {
				op += "set_" + std::to_string(current) + ".swap(set_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 24:
			op += "auto ithigh_" + std::to_string(m) + " = set_" + std::to_string(current) + ".upper_bound(" + generate_set_element(record_1.type) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		}



	}
	return op;
}





std::string create_set(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int set_elements_num = random_Int(5, 10);
	int set_rows = 2;// 1 for 1D vector
	std::set<int> temp_int = {};
	std::set<float> temp_float = {};
	std::set<double> temp_double = {};
	std::set<char> temp_char = {};
	std::set<bool> temp_bool = {};


	//temp 2D sets
	std::set<std::set<int>> temp_2d_int;
	std::set<std::set<double>> temp_2d_double;
	std::set<std::set<char>> temp_2d_char;
	std::set<std::set<bool>> temp_2d_bool;
	std::set<std::set<float>> temp_2d_float;

	std::vector<set_records> set_records;

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

		switch (random_Int(1, 5)) {
		case 1:
			type = "int";
			data_type = INT;
			break;
		case 2:
			type = "float";
			data_type = FLOAT;

			break;
		case 3:
			type = "double";
			data_type = DOUBLE;

			break;
		case 4:
			type = "char";
			data_type = CHAR;

			break;
		case 5:
			type = "bool";
			data_type = BOOL;

			break;

		case 6:
			type = "std::set<int>";
			data_type = INT_2D;

			break;
		case 7:
			type = "std::set<float>";
			data_type = FLOAT_2D;

			break;
		case 8:
			type = "std::set<double>";
			data_type = DOUBLE_2D;

			break;
		case 9:
			type = "std::set<char>";
			data_type = CHAR_2D;

			break;
		case 10:
			type = "std::set<bool>";
			data_type = BOOL_2D;

			break;

		}

		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D)
				set_records.push_back({ set_rows, type });
			else
				set_records.push_back({ 1, type });
		
			for (int m = 1; m <= set_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_set_int(set_elements_num);

					break;
				case FLOAT_2D: //float
					temp_float = create_set_float(set_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_set_double(set_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_set_char(set_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_set_bool(set_elements_num);
					break;
				}
				if (data_type == INT_2D) {
					int temp_size = temp_int.size();
					for (int i = 1; i <= temp_size; i++) {
						auto it = temp_int.begin();
						advance(it, i - 1);
						auto value = *it;
						oss += std::to_string(value);
						if (i != temp_size) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < set_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_int = {};
				}
				else if (data_type == FLOAT_2D) {
					int temp_size = temp_float.size();
					for (int i = 1; i <= temp_size; i++) {
						auto it = temp_float.begin();
						advance(it, i - 1);
						auto value = *it;
						oss += std::to_string(value);
						if (i != temp_size) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < set_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_float = {};
				}


				else if (data_type == DOUBLE_2D) {
					int temp_size = temp_double.size();
					for (int i = 1; i <= temp_size; i++) {
						auto it = temp_double.begin();
						advance(it, i - 1);
						auto value = *it;
						oss += std::to_string(value);
						if (i != temp_size) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < set_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}

					temp_double = {};
				}

				else if (data_type == CHAR_2D) {
					int temp_size = temp_char.size();
					for (int i = 1; i <= temp_size; i++) {
						auto it = temp_char.begin();
						advance(it, i - 1);
						auto value = *it;
						oss += std::to_string(value);
						if (i != temp_size) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < set_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_char = {};
				}

				else {
					int temp_size = temp_bool.size();
					for (int i = 1; i <= temp_size; i++) {
						auto it = temp_bool.begin();
						advance(it, i - 1);
						auto value = *it;
						oss += std::to_string(value);
						if (i != temp_size) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < set_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool = {};
				}


			}
			code += "	std::set<" + type + "> set_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		
		}


		else {
			switch (data_type) {
			case INT:
				temp_int = create_set_int(set_elements_num);
				break;

			case FLOAT:
				temp_float = create_set_float(set_elements_num);
				break;

			case DOUBLE:
				temp_double = create_set_double(set_elements_num);
				break;

			case CHAR:
				temp_char = create_set_char(set_elements_num);
				break;

			case BOOL:
				temp_bool = create_set_bool(set_elements_num);
				break;

			}



			if (data_type == INT) {
				int temp_size = temp_int.size();
				set_records.push_back({ temp_size, type });
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_int.begin();
					advance(it, i-1); 
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_int = {};
			}
			else if (data_type == FLOAT) {
				int temp_size = temp_float.size();
				set_records.push_back({ temp_size, type });
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_float.begin();
					advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_float = {};
			}


			else if (data_type == DOUBLE) {
				int temp_size = temp_double.size();
				set_records.push_back({ temp_size, type });
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_double.begin();
					advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_double = {};
			}

			else if (data_type == CHAR) {
				int temp_size = temp_char.size();
				set_records.push_back({ temp_size, type });
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_char.begin();
					advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}

				temp_char = {};
			}

			else {
				int temp_size = temp_bool.size();
				set_records.push_back({ 2, type });
				for (int i = 1; i <= temp_size; i++) {
					auto it = temp_bool.begin();
					advance(it, i - 1);
					auto value = *it;
					oss += std::to_string(value);
					if (i != temp_size) {
						oss += ", "; // Add a separator between numbers
					}
				}
				temp_bool = {};
			}


			//print out secton

			code += "	std::set<" + type + "> set_" + std::to_string(n) + " = {" + oss + "};\n";
			oss = {};

		}

	}

	//random operations generated
	code += random_set_op(index, set_records);

	//code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + set_records[m].type + "> newset_" + std::to_string(m) + "(set_" + std::to_string(m) + ".begin(), set_" + std::to_string(m) + ".end());\n";
		code += "	append_data(buffer, newset_" + std::to_string(m) + ");\n";

	}

	code += "\n";

	return code;


}
