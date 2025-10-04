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
#include <functional>

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
//else if (type == "std::vector<int>") {
//	std::vector<int> temp_int = create_vec_int(vec_elements_num);
//	op += "{";
//	for (int k = 1; k <= vec_elements_num; k++) {
//		op += std::to_string(temp_int[k - 1]);
//		if (k != vec_elements_num) {
//			op += ", "; // Add a separator between numbers
//		}
//	}
//	op += "}";
//	temp_int.clear();
//	return op;
//}
//else if (type == "std::vector<float>") {
//	std::vector<float> temp_float = create_vec_float(vec_elements_num);
//	op += "{";
//	for (int k = 1; k <= vec_elements_num; k++) {
//		op += std::to_string(temp_float[k - 1]);
//		if (k != vec_elements_num) {
//			op += ", "; // Add a separator between numbers
//		}
//	}
//	op += "}";
//	temp_float.clear();
//	return op;
//}
//else if (type == "std::vector<double>") {
//	std::vector<double> temp_double = create_vec_double(vec_elements_num);
//	op += "{";
//	for (int k = 1; k <= vec_elements_num; k++) {
//		op += std::to_string(temp_double[k - 1]);
//		if (k != vec_elements_num) {
//			op += ", "; // Add a separator between numbers
//		}
//	}
//	op += "}";
//	temp_double.clear();
//	return op;
//}
//else if (type == "std::vector<char>") {
//	std::vector<char> temp_char = create_vec_char(vec_elements_num);
//	op += "{";
//	for (int k = 1; k <= vec_elements_num; k++) {
//		op += std::to_string(temp_char[k - 1]);
//		if (k != vec_elements_num) {
//			op += ", "; // Add a separator between numbers
//		}
//	}
//	op += "}";
//	temp_char.clear();
//	return op;
//}
//else if (type == "std::vector<bool>") {
//	std::vector<bool> temp_bool = create_vec_bool(vec_elements_num);
//	op += "{";
//	for (int k = 1; k <= vec_elements_num; k++) {
//		op += std::to_string(temp_bool[k - 1]);
//		if (k != vec_elements_num) {
//			op += ", "; // Add a separator between numbers
//		}
//	}
//	op += "}";
//	temp_bool.clear();
//	return op;
//}

//}
std::vector<vector_records> merge_records_min_length(
	const std::vector<vector_records>& records1,
	const std::vector<vector_records>& records2
) {
	std::vector<vector_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		vector_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}

std::string arithmatic_block(int n, std::vector<vector_records> vec_records, int operation_numbers = 5) {
	std::string oss;
	int current = 0;
	int current_2 = 0;
	std::vector<vector_records> local_records = vec_records;
	for (int m = 1; m <= operation_numbers; m++) {
		current = randomInt(0, n - 1);
		current_2 = randomInt(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		switch (random_Int(1, 6)) {
		case 1:
			oss += "	auto arith_vec_"+ std::to_string(m) +" = std::plus()(vec_" + std::to_string(current) 
				+"["+ std::to_string(random_Int(0, record_1.length - 1)) +"], " + generate_element(record_1.type) + "); \n";
			break;
		case 2:
			oss += "	auto arith_vec_" + std::to_string(m) + " = std::minus()(vec_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_element(record_1.type) + "); \n";
			break;
		case 3:
			oss += "	auto arith_vec_" + std::to_string(m) + " = std::multiplies()(vec_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_element(record_1.type) + "); \n";
			break;
		case 4:
			oss += "	auto arith_vec_" + std::to_string(m) + " = std::divides()(vec_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_element(record_1.type) + "); \n";
			break;
		case 5:
			oss += "	auto arith_vec_" + std::to_string(m) + " = std::modulus()(vec_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "], " + generate_element(record_1.type) + "); \n";
			break;
		case 6:
			oss += "	auto arith_vec_" + std::to_string(m) + " = std::negate()(vec_" + std::to_string(current)
				+ "[" + std::to_string(random_Int(0, record_1.length - 1)) + "] ); \n";
			break;

		}

	}
	return oss;
}

std::pair<std::string, std::vector<vector_records>> random_vec_op(int n, std::vector<vector_records> vec_records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<vector_records> local_records = vec_records;
	int random_size = randomInt(0, 19);

	//移出所有已生成函数的rdm

	for (int m = 1; m <= operation_numbers; m++) {
		current = randomInt(0, n - 1);
		current_2 = randomInt(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		int multiple_insert = random_Int(0, 10);
		int multiple_insert_list_case = random_Int(0, 10);
		std::string oss;
		switch (randomInt(1, 31)) {
		case 1:
			op += "	vec_" + std::to_string(current) + ".push_back(" + generate_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
			local_records[current].length += 1 * loop_index;
			break;
		case 2:
			switch (random_Int(1, 4)) {
			case 1:
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin()," + generate_element(record_1.type) + "); \n"; //insert at certain place
				}
				else {
					op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "," + generate_element(record_1.type) + "); \n"; //insert at certain place
				}
				local_records[current].length += 1 * loop_index;
				break;
			case 2:
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin()," + std::to_string(multiple_insert) + ", " + generate_element(record_1.type) + "); \n"; //insert at certain place
				}
				else {
					op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "," + std::to_string(multiple_insert) + ", " + generate_element(record_1.type) + "); \n"; //insert at certain place
				}
				local_records[current].length += multiple_insert * loop_index;
				break;
			case 3:
				if (record_1.type == "int") {
					auto temp_int = create_vec_int(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_int[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
				}
				else if (record_1.type == "float") {
					auto temp_float = create_vec_float(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_float[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}

					temp_float = {};
				}
				else if (record_1.type == "double") {
					auto temp_double = create_vec_double(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_double[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}

					temp_double = {};
				}

				else if (record_1.type == "char") {
					auto temp_char = create_vec_char(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_char[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}

					temp_char = {};
				}

				else if (record_1.type == "bool") {
					auto temp_bool = create_vec_bool(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_bool[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_bool = {};
				}

				else if (record_1.type == "unsigned char") {
					auto temp_uchar = create_vec_uchar(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_uchar[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_uchar = {};
				}
				else if (record_1.type == "unsigned short") {
					auto temp_ushort = create_vec_ushort(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_ushort[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_ushort = {};
				}
				else if (record_1.type == "short") {
					auto temp_short = create_vec_short(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_short[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_short = {};
				}
				else if (record_1.type == "unsigned int") {
					auto temp_uint = create_vec_uint(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_uint[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_uint = {};
				}
				else if (record_1.type == "unsigned long") {
					auto temp_ulong = create_vec_ulong(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_ulong[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_ulong = {};
				}
				else if (record_1.type == "long") {
					auto temp_long = create_vec_long(multiple_insert_list_case);
					for (int i = 1; i <= multiple_insert_list_case; i++) {
						oss += std::to_string(temp_long[i - 1]);
						if (i != multiple_insert_list_case) {
							oss += ", "; // Add a separator between numbers
						}
					}
					temp_long = {};
				}
				op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + ", {" + oss + "}); \n"; //insert at certain place
				local_records[current].length += multiple_insert_list_case * loop_index;
				oss = {};
				break;
			case 4:
				if (record_1.type == record_2.type) {
					op += "	vec_" + std::to_string(current) + ".insert(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) 
						+ ", vec_" + std::to_string(current_2) +".begin() ,vec_" +std::to_string(current_2) + ".end()); \n"; 
					local_records[current].length += record_2.length * loop_index;
				}
				break;
			}

			break;
		case 3:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".erase(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 4:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".pop_back();\n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 5:
			op += "	vec_" + std::to_string(current) + ".resize(" + std::to_string(random_size) + "," + generate_element(record_1.type) + ");\n";
			local_records[current].length = random_size;
			break;
		case 6:
			op += "	vec_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;
		case 7:
			op += "	vec_" + std::to_string(current) + ".assign(static_cast<size_t> (" + std::to_string(random_size) + "), " + generate_element(record_1.type) + ");\n";
			local_records[current].length = random_size;
			break;
		case 8:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduce capacity to fit size
			break;
		case 9:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	vec_" + std::to_string(current) + ".swap(vec_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 10:
			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
				or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
				or record_1.type == "unsigned long") {
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
			local_records[current].length += 1 * loop_index;
			break;
		case 11:
			op += "	vec_" + std::to_string(current) + ".capacity();\n"; // Print capacity
			break;
		case 12:
			op += "	vec_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 13:
			op += "	vec_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;
		case 14:
			op += "	vec_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 15:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".at(" + std::to_string(random_Int(0, record_1.length - 1)) + "); \n"; //Accesses the element at a specific position, with bounds checking.
			}
			break;
		case 16:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
			}
			break;
		case 17:
			if (record_1.length != 0) {
				op += "	vec_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
			}
			break;
		case 18:
			op += "	vec_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 19:
			op += "	vec_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 20:
			op += "	vec_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 21:
			op += "	vec_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 22:
			op += "	vec_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 23:
			op += "	vec_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 24:
			op += "	vec_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 25:
			op += "	vec_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;
		case 26:
			op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduces memory usage by freeing unused space.
			break;

		case 27:

			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
				or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
				or record_1.type == "unsigned long") {
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin()," + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", " + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.

				}
			}
			else if (record_1.type == "std::vector<int>")
			{
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin(), std::initializer_list<int>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<int>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
			}
			else if (record_1.type == "std::vector<float>") {
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin(), std::initializer_list<float>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<float>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.

				}
			}
			else if (record_1.type == "std::vector<double>") {
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin(), std::initializer_list<double>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<double>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.

				}
			}
			else if (record_1.type == "std::vector<char>") {
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin(), std::initializer_list<char>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<char>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
			}
			else if (record_1.type == "std::vector<bool>") {
				if (record_1.length == 0) {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin(), std::initializer_list<bool>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
				else {
					op += "	vec_" + std::to_string(current) + ".emplace(vec_" + std::to_string(current) + ".begin() + " + std::to_string(random_Int(0, record_1.length - 1)) + ", std::initializer_list<bool>" + generate_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
				}
			}

			local_records[current].length += 1 * loop_index;
			break;
		case 28:
			op += "	vec_" + std::to_string(current) + ".reserve(" + std::to_string(randomInt(1, 100)) + "); \n"; // Requests that the vector capacity be at least enough to contain a specified number of elements.
			break;


		}




	}



	vec_records = local_records;
	return { op,vec_records };
}

std::string random_vec_loop(int number_of_index, std::vector<vector_records> vec_records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	//std::vector<vector_records> local_records = vec_records;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = randomInt(0, number_of_index - 1);
		auto record_1 = vec_records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] > " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] < " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] <= " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] >= " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] == " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (vec_" + std::to_string(current) + "[" + std::to_string(idx) + "] != " + generate_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_vec_op(number_of_index, vec_records, random_Int(0, 5));
				vec_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
			//case 7:
			//	if (record_1.length > for_loop_size) {
			//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
			//		auto [temp_string, temp_records] = random_vec_op(number_of_index, vec_records, 1, for_loop_size);
			//		vec_records = temp_records;
			//		op += temp_string;
			//		op += "	}\n";
			//	}
			//	break;

			//case 8:
			//	if (record_1.length > for_loop_size) {
			//		op += "	int index_vec_" + std::to_string(m) + "= 0;\n";
			//		op += "	while (index_vec_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
			//		auto [temp_string, temp_records] = random_vec_op(number_of_index, vec_records, 1, for_loop_size);
			//		vec_records = temp_records;
			//		op += temp_string;
			//		op += "	index_vec_" + std::to_string(m) + "++;\n";
			//		op += "	}\n";
			//	}
			//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}

std::tuple<std::string, std::string,std::vector<vector_records>> create_vec(int index) {
	std::string code; 
	std::string oss;
	std::string type;
	int vec_elements_num = random_Int(1, 20);

	/*int vec_rows = random_Int(1, 2);*/
	int vec_rows = 1;// 1 for 1D vector
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

	std::vector<vector_records> vec_records;


	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {
		int creation_type = random_Int(1, 3);
		int vector_selection = random_Int(0, vec_records.size() - 1);
		auto [data_type, type] = random_type();

		vec_records.push_back({ vec_elements_num, type });



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

			code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		}

		else {
			switch (creation_type) {
			case 1:
				switch (data_type) {
				case INT:
					temp_int = create_vec_int(vec_elements_num);
					oss += vector_to_string(temp_int);

					temp_int = {};
					break;

				case FLOAT:
					temp_float = create_vec_float(vec_elements_num);
					oss += vector_to_string(temp_float);

					temp_float = {};
					break;

				case DOUBLE:
					temp_double = create_vec_double(vec_elements_num);
					oss += vector_to_string(temp_double);

					temp_double = {};
					break;

				case CHAR:
					temp_char = create_vec_char(vec_elements_num);
					oss += vector_to_string(temp_char);

					temp_char = {};
					break;

				case BOOL:
					temp_bool = create_vec_bool(vec_elements_num);
					oss += vector_to_string(temp_bool);
					temp_bool = {};
					break;
				case UCHAR:
					temp_uchar = create_vec_uchar(vec_elements_num);
					oss += vector_to_string(temp_uchar);
					temp_uchar = {};
					break;
				case USHORT:
					temp_ushort = create_vec_ushort(vec_elements_num);
					oss += vector_to_string(temp_ushort);
					temp_ushort = {};
					break;
				case SHORT:
					temp_short = create_vec_short(vec_elements_num);
					oss += vector_to_string(temp_short);
					temp_short = {};
					break;
				case UINT:
					temp_uint = create_vec_uint(vec_elements_num);
					oss += vector_to_string(temp_uint);
					temp_uint = {};
					break;
				case ULONG:
					temp_ulong = create_vec_ulong(vec_elements_num);
					oss += vector_to_string(temp_ulong);
					temp_ulong = {};
					break;
				case LONG:
					temp_long = create_vec_long(vec_elements_num);
					oss += vector_to_string(temp_long);
					temp_long = {};
					break;

				}
				code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = {" + oss + "};\n";
				oss = {};
				break;
			case 2:

				code += "	std::vector<" + type + "> vec_" + std::to_string(n) + "(" + std::to_string(vec_elements_num) + ", "
					+ generate_element(type) + ");\n";
				break;

			case 3:
				if (n > 0 && type == vec_records[vector_selection].type) {
					code += "	std::vector<" + type + "> vec_" + std::to_string(n) + "(vec_" + std::to_string(vector_selection) + ".begin(), vec_" + std::to_string(vector_selection) + ".end());\n";
				}
				else {
					switch (data_type) {
					case INT:
						temp_int = create_vec_int(vec_elements_num);
						oss += vector_to_string(temp_int);

						temp_int = {};
						break;

					case FLOAT:
						temp_float = create_vec_float(vec_elements_num);
						oss += vector_to_string(temp_float);

						temp_float = {};
						break;

					case DOUBLE:
						temp_double = create_vec_double(vec_elements_num);
						oss += vector_to_string(temp_double);

						temp_double = {};
						break;

					case CHAR:
						temp_char = create_vec_char(vec_elements_num);
						oss += vector_to_string(temp_char);

						temp_char = {};
						break;

					case BOOL:
						temp_bool = create_vec_bool(vec_elements_num);
						oss += vector_to_string(temp_bool);
						temp_bool = {};
						break;
					case UCHAR:
						temp_uchar = create_vec_uchar(vec_elements_num);
						oss += vector_to_string(temp_uchar);
						temp_uchar = {};
						break;
					case USHORT:
						temp_ushort = create_vec_ushort(vec_elements_num);
						oss += vector_to_string(temp_ushort);
						temp_ushort = {};
						break;
					case SHORT:
						temp_short = create_vec_short(vec_elements_num);
						oss += vector_to_string(temp_short);
						temp_short = {};
						break;
					case UINT:
						temp_uint = create_vec_uint(vec_elements_num);
						oss += vector_to_string(temp_uint);
						temp_uint = {};
						break;
					case ULONG:
						temp_ulong = create_vec_ulong(vec_elements_num);
						oss += vector_to_string(temp_ulong);
						temp_ulong = {};
						break;
					case LONG:
						temp_long = create_vec_long(vec_elements_num);
						oss += vector_to_string(temp_long);
						temp_long = {};
						break;

					}

					code += "	std::vector<" + type + "> vec_" + std::to_string(n) + " = {" + oss + "};\n";
					oss = {};
				}
			}

		}

	}
	//random operations generated
	//code += arithmatic_block(index, vec_records);
	auto vec_init = code;
	code.clear();
	for (const auto& rec : vec_records) {
		std::cout << "Vector Length: " << rec.length
			<< "Vector Type: " << rec.type << std::endl;
	}
	auto output_record = vec_records;
	auto [temp_string, temp_records] = random_vec_op(index, vec_records);
	code += temp_string;
	vec_records = temp_records;


	code += random_vec_loop(index, vec_records, 1);

	for (int m = 0; m < index; m++) {
		code += "	append_data(buffer, vec_" + std::to_string(m) + ");\n";

	}




	code += "\n";
	return { vec_init,code,output_record };
}
