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

std::deque<int> create_deq_int(int length = 1) {
	std::deque<int> temp;
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

std::deque<float> create_deq_float(int length = 1) {
	std::deque<float> temp;
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

std::deque<double> create_deq_double(int length = 1) {
	std::deque<double> temp;
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

std::deque<char> create_deq_char(int length = 1) {
	std::deque<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::deque<bool> create_deq_bool(int length = 1) {
	std::deque<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}
std::deque<unsigned int> create_deq_uint(int length = 1) {
	std::deque<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UInt(0, 100));
	}
	return temp;
}

std::deque<short> create_deq_short(int length = 1) {
	std::deque<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Short(-100, 100));
	}

	return temp;
}

std::deque<unsigned short> create_deq_ushort(int length = 1) {
	std::deque<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UShort(0, 100));
	}

	return temp;
}

std::deque<unsigned char> create_deq_uchar(int length = 1) {
	std::deque<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UChar());
	}

	return temp;
}

std::deque<long> create_deq_long(int length = 1) {
	std::deque<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Long(-100, 100));
	}

	return temp;
}

std::deque<unsigned long> create_deq_ulong(int length = 1) {
	std::deque<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_ULong(0, 100));
	}

	return temp;
}



std::string generate_deque_element(std::string type) {
	std::string op;
	int deq_elements_num = random_Int(5, 10);
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
	else if (type == "std::deque<int>") {
		std::deque<int> temp_int = create_deq_int(deq_elements_num);
		op += "{";
		for (int k = 1; k <= deq_elements_num; k++) {
			op += std::to_string(temp_int[k - 1]);
			if (k != deq_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_int.clear();
		return op;
	}
	else if (type == "std::deque<float>") {
		std::deque<float> temp_float = create_deq_float(deq_elements_num);
		op += "{";
		for (int k = 1; k <= deq_elements_num; k++) {
			op += std::to_string(temp_float[k - 1]);
			if (k != deq_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_float.clear();
		return op;
	}
	else if (type == "std::deque<double>") {
		std::deque<double> temp_double = create_deq_double(deq_elements_num);
		op += "{";
		for (int k = 1; k <= deq_elements_num; k++) {
			op += std::to_string(temp_double[k - 1]);
			if (k != deq_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_double.clear();
		return op;
	}
	else if (type == "std::deque<char>") {
		std::deque<char> temp_char = create_deq_char(deq_elements_num);
		op += "{";
		for (int k = 1; k <= deq_elements_num; k++) {
			op += std::to_string(temp_char[k - 1]);
			if (k != deq_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_char.clear();
		return op;
	}
	else if (type == "std::deque<bool>") {
		std::deque<bool> temp_bool = create_deq_bool(deq_elements_num);
		op += "{";
		for (int k = 1; k <= deq_elements_num; k++) {
			op += std::to_string(temp_bool[k - 1]);
			if (k != deq_elements_num) {
				op += ", "; // Add a separator between numbers
			}
		}
		op += "}";
		temp_bool.clear();
		return op;
	}

}

std::vector<deque_records> merge_records_min_length(
	const std::vector<deque_records>& records1,
	const std::vector<deque_records>& records2
) {
	std::vector<deque_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		deque_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}


std::pair<std::string, std::vector<deque_records>> random_deq_op(int n, std::vector<deque_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<deque_records> local_records = records;
	int random_size = random_Int(0, 19);//specific for VC Formal

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 29)) {
		case 1:
			if (record_1.length < 20) {
				op += "	deq_" + std::to_string(current) + ".push_front(" + generate_deque_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1*loop_index;
			}
			break;
		case 2:
			if (record_1.length < 20) {
				op += "	deq_" + std::to_string(current) + ".push_back(" + generate_deque_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1 * loop_index;
			}
			break;
		case 3:
			if (record_1.length > 0) {
				op += "	deq_" + std::to_string(current) + ".pop_front(); \n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 4:
			if (record_1.length > 0) {
				op += "	deq_" + std::to_string(current) + ".pop_back();\n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 5:
			op += "	deq_" + std::to_string(current) + ".size();\n";
			break;
		case 6:
			op += "	deq_" + std::to_string(current) + ".max_size();\n";
			break;
		case 7:
			
			op += "	deq_" + std::to_string(current) + ".resize(" + std::to_string(random_size) + ");\n";
			local_records[current].length = random_size;
			break;
		case 8:
			op += "	deq_" + std::to_string(current) + ".empty();\n";
			break;
		case 9:
			if (record_1.length != 0) {
				op += "	deq_" + std::to_string(current) + ".at(" + std::to_string(random_Int(0, record_1.length - 1)) + ");\n";
			}
			break;
		case 10:
			if (record_1.length != 0) {
				op += "	deq_" + std::to_string(current) + ".front();\n";
			}
			break;
		case 11:
			if (record_1.length != 0) {
				op += "	deq_" + std::to_string(current) + ".back();\n";
			}
			break;
		case 12:
			op += "	deq_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 13:
			op += "	deq_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 14:
			op += "	deq_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 15:
			op += "	deq_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 16:
			op += "	deq_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 17:
			op += "	deq_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 18:
			op += "	deq_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 19:
			op += "	deq_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;
		case 20:
			if (record_1.length < 20) {
				if (record_1.length == 0) {
					op += "	deq_" + std::to_string(current) + ".insert(deq_" + std::to_string(current) + ".begin()," + generate_deque_element(record_1.type) + "); \n"; //insert at certain place
				}
				else {
					op += "	deq_" + std::to_string(current) + ".insert(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "," + generate_deque_element(record_1.type) + "); \n"; //insert at certain place
				}
				local_records[current].length += 1 * loop_index;
			}
			break;
		case 21:
			if (record_1.length != 0) {
				op += "	deq_" + std::to_string(current) + ".erase(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 22:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	deq_" + std::to_string(current) + ".swap(deq_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 23:
			op += "	deq_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;

		case 24:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
					or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
					or record_1.type == "unsigned long") {
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin()," + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + "," + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
				}
				else if (record_1.type == "std::deque<int>")
				{
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin(), std::deque<int>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::deque<int>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
				}
				else if (record_1.type == "std::deque<float>")
				{
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin(), std::deque<float>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::deque<float>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
				}
				else if (record_1.type == "std::deque<double>")
				{
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin(), std::deque<double>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::deque<double>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}

				}
				else if (record_1.type == "std::deque<char>") {
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin(), std::deque<char>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::deque<char>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
				}
				else if (record_1.type == "std::deque<bool>") {
					if (record_1.length == 0) {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin(), std::deque<bool>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
					else {
						op += "	deq_" + std::to_string(current) + ".emplace(deq_" + std::to_string(current) + ".begin() +" + std::to_string(random_Int(0, record_1.length - 1)) + " ,std::deque<bool>" + generate_deque_element(record_1.type) + "); \n"; // Constructs and inserts an element in the vector.
					}
				}
				local_records[current].length += 1 * loop_index;
			}
			break;


		case 26:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
					or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
					or record_1.type == "unsigned long") {
					op += "	deq_" + std::to_string(current) + ".emplace_back(" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				}
				else if (record_1.type == "std::deque<int>")
					op += "	deq_" + std::to_string(current) + ".emplace_back(std::deque<int>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<float>")
					op += "	deq_" + std::to_string(current) + ".emplace_back(std::deque<float>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<double>")
					op += "	deq_" + std::to_string(current) + ".emplace_back(std::deque<double>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<char>")
					op += "	deq_" + std::to_string(current) + ".emplace_back(std::deque<char>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<bool>")
					op += "	deq_" + std::to_string(current) + ".emplace_back(std::deque<bool>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				local_records[current].length += 1 * loop_index;
			}
			break;

		case 27:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
					or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
					or record_1.type == "unsigned long") {
					op += "	deq_" + std::to_string(current) + ".emplace_front(" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				}
				else if (record_1.type == "std::deque<int>")
					op += "	deq_" + std::to_string(current) + ".emplace_front(std::deque<int>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<float>")
					op += "	deq_" + std::to_string(current) + ".emplace_front(std::deque<float>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<double>")
					op += "	deq_" + std::to_string(current) + ".emplace_front(std::deque<double>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<char>")
					op += "	deq_" + std::to_string(current) + ".emplace_front(std::deque<char>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::deque<bool>")
					op += "	deq_" + std::to_string(current) + ".emplace_front(std::deque<bool>" + generate_deque_element(record_1.type) + ");\n"; // Efficient push_back
				local_records[current].length += 1 * loop_index;
			}
			break;
		case 28:
			op += "	deq_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduces memory usage by freeing unused space.
			break;
		case 29:
			op += "	deq_" + std::to_string(current) + ".assign(static_cast<size_t> (" + std::to_string(random_size) + ")," + generate_deque_element(record_1.type) + ");\n";
			local_records[current].length = random_size;
			break;


		}

	}



	records = local_records;
	return { op,records };
}

std::string random_deque_loop(int number_of_index, std::vector<deque_records> deq_records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = deq_records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] > " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] < " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] <= " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] >= " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] == " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	if (deq_" + std::to_string(current) + "[" + std::to_string(idx) + "] != " + generate_deque_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_deq_op(number_of_index, deq_records, random_Int(0, 5));
				deq_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_deq_op(number_of_index, deq_records, 1, for_loop_size);
		//		deq_records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_deq_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_deq_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_deq_op(number_of_index, deq_records, 1, for_loop_size);
		//		deq_records = temp_records;
		//		op += temp_string;
		//		op += "	index_deq_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}



std::tuple<std::string, std::string, std::vector<deque_records>> create_deque(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int deque_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int deque_rows = 2;// 1 for 1D vector
	//temp vectors
	std::deque<int> temp_int = {};
	std::deque<float> temp_float = {};
	std::deque<double> temp_double = {};
	std::deque<char> temp_char = {};
	std::deque<bool> temp_bool = {};
	std::deque<unsigned int> temp_uint = {};
	std::deque<short> temp_short = {};
	std::deque<unsigned short> temp_ushort = {};
	std::deque<unsigned char> temp_uchar = {};
	std::deque<long> temp_long = {};
	std::deque<unsigned long> temp_ulong = {};

	//temp 2D vectors
	std::deque<std::deque<int>> temp_2d_int;
	std::deque<std::deque<double>> temp_2d_double;
	std::deque<std::deque<char>> temp_2d_char;
	std::deque<std::deque<bool>> temp_2d_bool;
	std::deque<std::deque<float>> temp_2d_float;
	/*std::vector<std::pair<int, std::string>> vec_records = {};*/

	std::vector<deque_records> deq_records;


	aval_Type data_type = NONE;


	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();

		deq_records.push_back({ deque_elements_num, type });
		//vec_records.push_back({ vec_elements_num, type });


		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			for (int m = 1; m <= deque_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_deq_int(deque_elements_num);
					break;
				case FLOAT_2D: //float
					temp_float = create_deq_float(deque_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_deq_double(deque_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_deq_char(deque_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_deq_bool(deque_elements_num);
					break;
				}


				if (data_type == INT_2D) {
					temp_2d_int.push_back(temp_int);
					for (int k = 1; k <= deque_elements_num; k++) {
						oss += std::to_string(temp_int[k - 1]);
						if (k != deque_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < deque_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_int.clear();
				}
				else if (data_type == FLOAT_2D) {
					temp_2d_float.push_back(temp_float);
					for (int k = 1; k <= deque_elements_num; k++) {
						oss += std::to_string(temp_float[k - 1]);
						if (k != deque_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < deque_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_float.clear();
				}
				else if (data_type == DOUBLE_2D) {
					temp_2d_double.push_back(temp_double);
					for (int k = 1; k <= deque_elements_num; k++) {
						oss += std::to_string(temp_double[k - 1]);
						if (k != deque_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < deque_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_double.clear();
				}
				else if (data_type == CHAR_2D) {
					temp_2d_char.push_back(temp_char);
					for (int k = 1; k <= deque_elements_num; k++) {
						oss += std::to_string(temp_char[k - 1]);
						if (k != deque_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < deque_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_char.clear();
				}
				else if (data_type == BOOL_2D) {
					temp_2d_bool.push_back(temp_bool);
					for (int k = 1; k <= deque_elements_num; k++) {
						oss += std::to_string(temp_bool[k - 1]);
						if (k != deque_elements_num) {
							oss += ", "; // Add a separator between numbers
						}
					}
					if (m < deque_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool.clear();
				}


			}

			code += "	std::deque<" + type + "> deq_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};
		}

		else {
			switch (data_type) {
			case INT:
				temp_int = create_deq_int(deque_elements_num);
				oss += deque_to_string(temp_int);

				temp_int = {};
				break;

			case FLOAT:
				temp_float = create_deq_float(deque_elements_num);
				oss += deque_to_string(temp_float);

				temp_float = {};
				break;

			case DOUBLE:
				temp_double = create_deq_double(deque_elements_num);
				oss += deque_to_string(temp_double);

				temp_double = {};
				break;

			case CHAR:
				temp_char = create_deq_char(deque_elements_num);
				oss += deque_to_string(temp_char);

				temp_char = {};
				break;

			case BOOL:
				temp_bool = create_deq_bool(deque_elements_num);
				oss += deque_to_string(temp_bool);
				temp_bool = {};
				break;
			case UCHAR:
				temp_uchar = create_deq_uchar(deque_elements_num);
				oss += deque_to_string(temp_uchar);
				temp_uchar = {};
				break;
			case USHORT:
				temp_ushort = create_deq_ushort(deque_elements_num);
				oss += deque_to_string(temp_ushort);
				temp_ushort = {};
				break;
			case SHORT:
				temp_short = create_deq_short(deque_elements_num);
				oss += deque_to_string(temp_short);
				temp_short = {};
				break;
			case UINT:
				temp_uint = create_deq_uint(deque_elements_num);
				oss += deque_to_string(temp_uint);
				temp_uint = {};
				break;
			case ULONG:
				temp_ulong = create_deq_ulong(deque_elements_num);
				oss += deque_to_string(temp_ulong);
				temp_ulong = {};
				break;
			case LONG:
				temp_long = create_deq_long(deque_elements_num);
				oss += deque_to_string(temp_long);
				temp_long = {};
				break;

			}


			//print out secton
			switch (random_Int(1, 3)) {
			case 1:
				code += "	std::deque<" + type + "> deq_" + std::to_string(n) + " = {" + oss + "};\n";
				break;
			case 2:
				code += "	std::deque<" + type + "> deq_" + std::to_string(n) + "(" +std::to_string(deque_elements_num)+","+ generate_deque_element(type) + ");\n";
				break;
			case 3:
				code += "	std::deque<" + type + "> deq_" + std::to_string(n) + "(" + std::to_string(deque_elements_num) + ");\n";
				break;
			}
			oss = {};

		}

	}
	auto deq_init = code;
	code.clear();
	auto output_record = deq_records;
	//random operations generated
	auto [temp_string, temp_records] = random_deq_op(index, deq_records);
	code += temp_string;
	deq_records = temp_records;

	code += random_deque_loop(index, deq_records,1);

	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + deq_records[m].type + "> newdeq_" + std::to_string(m) + "(deq_" + std::to_string(m) + ".begin(), deq_" + std::to_string(m) + ".end());\n";
		code += "	append_data(buffer, newdeq_" + std::to_string(m) + ");\n";

	}

	code += "\n";

	//for (const auto& record : deq_records) {
	//	std::cout << "Deque length: " << record.length
	//		<< ", Type: " << record.type << std::endl;
	//}


	code += "\n";
	return { deq_init,code,output_record };
}

