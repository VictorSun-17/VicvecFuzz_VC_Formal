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
#include <list>



std::list<int> create_list_int(int length = 1) {
	std::list<int> temp;
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

std::list<float> create_list_float(int length = 1) {
	std::list<float> temp;
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

std::list<double> create_list_double(int length = 1) {
	std::list<double> temp;
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

std::list<char> create_list_char(int length = 1) {
	std::list<char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Char());
	}
	return temp;
}

std::list<bool> create_list_bool(int length = 1) {
	std::list<bool> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Bool());
	}
	return temp;
}
std::list<unsigned int> create_list_uint(int length = 1) {
	std::list<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UInt(0, 100));
	}
	return temp;
}

std::list<short> create_list_short(int length = 1) {
	std::list<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Short(-100, 100));
	}

	return temp;
}

std::list<unsigned short> create_list_ushort(int length = 1) {
	std::list<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UShort(0, 100));
	}

	return temp;
}

std::list<unsigned char> create_list_uchar(int length = 1) {
	std::list<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UChar());
	}

	return temp;
}

std::list<long> create_list_long(int length = 1) {
	std::list<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Long(-100, 100));
	}

	return temp;
}

std::list<unsigned long> create_list_ulong(int length = 1) {
	std::list<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_ULong(0, 100));
	}

	return temp;
}



std::string generate_list_element(std::string type) {
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
	else if (type == "std::list<int>") {
		std::list<int> temp_int = create_list_int(vec_elements_num);
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
	else if (type == "std::list<float>") {
		std::list<float> temp_float = create_list_float(vec_elements_num);
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
	else if (type == "std::list<double>") {
		std::list<double> temp_double = create_list_double(vec_elements_num);
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
	else if (type == "std::list<char>") {
		std::list<char> temp_char = create_list_char(vec_elements_num);
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
	else if (type == "std::list<bool>") {
		std::list<bool> temp_bool = create_list_bool(vec_elements_num);
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

std::vector<list_records> merge_records_min_length(
	const std::vector<list_records>& records1,
	const std::vector<list_records>& records2
) {
	std::vector<list_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		list_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}


std::pair<std::string, std::vector<list_records>> random_list_op(int n, std::vector<list_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<list_records> local_records = records;
	int random_size = random_Int(0, 19);

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 27)) {
		case 1:
			if (record_1.length < 20) {
				op += "	list_" + std::to_string(current) + ".push_front(" + generate_list_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1* loop_index;
			}
			break;
		case 2:
			if (record_1.length < 20) {
				op += "	list_" + std::to_string(current) + ".push_back(" + generate_list_element(record_1.type) + "); \n";//Adds an element to the end of the vector.
				local_records[current].length += 1* loop_index;
			}
			break;
		case 3:
			if (record_1.length < 20) {
				if (record_1.length == 0) {
					op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
					op += "	list_" + std::to_string(current) + ".insert(list_it_" + std::to_string(m) + ", " + generate_list_element(record_1.type) + ");\n";
				}
				else {
					op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
					op += "	list_" + std::to_string(current) + ".insert(list_it_" + std::to_string(m) + "," + generate_list_element(record_1.type) + "); \n"; //insert at certain place
				}
				local_records[current].length += 1* loop_index;
			}
			break;
		case 4:
			if (record_1.length != 0) {
				op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	list_" + std::to_string(current) + ".erase(list_it_" + std::to_string(m) + "); \n";
				local_records[current].length -= 1* loop_index;
			}
			break;
		case 5:
			if (record_1.length != 0) {
				op += "	list_" + std::to_string(current) + ".pop_back();\n";
				local_records[current].length -= 1* loop_index;
			}
			break;

		case 6:
			if (record_1.length != 0) {
				op += "	list_" + std::to_string(current) + ".pop_front();\n";
				local_records[current].length -= 1* loop_index;
			}
			break;
		case 7:
			op += "	list_" + std::to_string(current) + ".sort();\n";
			break;
		case 8:
			op += "	list_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;
		case 9:
			op += "	list_" + std::to_string(current) + ".assign(static_cast<size_t> (" + std::to_string(random_size) + ")," + generate_list_element(record_1.type) + ");\n";
			local_records[current].length = random_size;
			break;
			//case 10:
			//	op += "	vec_" + std::to_string(current) + ".shrink_to_fit();\n"; // Reduce capacity to fit size
			//	break;
		case 10:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	list_" + std::to_string(current) + ".swap(list_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 11:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool" 
					or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
					or record_1.type == "unsigned long") {
					op += "	list_" + std::to_string(current) + ".emplace_front(" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				}
				else if (record_1.type == "std::list<int>")
					op += "	list_" + std::to_string(current) + ".emplace_front(std::initializer_list<int>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<float>")
					op += "	list_" + std::to_string(current) + ".emplace_front(std::initializer_list<float>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<double>")
					op += "	list_" + std::to_string(current) + ".emplace_front(std::initializer_list<double>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<char>")
					op += "	list_" + std::to_string(current) + ".emplace_front(std::initializer_list<char>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<bool>")
					op += "	list_" + std::to_string(current) + ".emplace_front(std::initializer_list<bool>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				local_records[current].length += 1* loop_index;
			}
			break;

		case 12:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
					or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
					or record_1.type == "unsigned long") {
					op += "	list_" + std::to_string(current) + ".emplace_back(" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				}
				else if (record_1.type == "std::list<int>")
					op += "	list_" + std::to_string(current) + ".emplace_back(std::initializer_list<int>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<float>")
					op += "	list_" + std::to_string(current) + ".emplace_back(std::initializer_list<float>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<double>")
					op += "	list_" + std::to_string(current) + ".emplace_back(std::initializer_list<double>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<char>")
					op += "	list_" + std::to_string(current) + ".emplace_back(std::initializer_list<char>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				else if (record_1.type == "std::list<bool>")
					op += "	list_" + std::to_string(current) + ".emplace_back(std::initializer_list<bool>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
				local_records[current].length += 1* loop_index;
			}
			break;
		case 13:
			if (record_1.length < 20) {
				if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", " + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", " + generate_list_element(record_1.type) + ");\n"; // Efficient push_back

					}
				}
				else if (record_1.type == "std::list<int>") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ",  std::initializer_list<int>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", std::initializer_list<int>" + generate_list_element(record_1.type) + "); \n"; // Efficient push_back

					}
				}
				else if (record_1.type == "std::list<float>") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ",  std::initializer_list<float>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", std::initializer_list<float>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back

					}
				}
				else if (record_1.type == "std::list<double>") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ",  std::initializer_list<double>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", std::initializer_list<double>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
				}
				else if (record_1.type == "std::list<char>") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ",  std::initializer_list<char>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", std::initializer_list<char>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
				}
				else if (record_1.type == "std::list<bool>") {
					if (record_1.length == 0) {
						op += "	auto list_it_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin(); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ",  std::initializer_list<bool>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
					else {
						op += "	auto list_it_" + std::to_string(m) + " = next(list_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
						op += "	list_" + std::to_string(current) + ".emplace(list_it_" + std::to_string(m) + ", std::initializer_list<bool>" + generate_list_element(record_1.type) + ");\n"; // Efficient push_back
					}
				}
				local_records[current].length += 1* loop_index;
			}
			break;
		case 14:
			op += "	list_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 15:
			op += "	list_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;
		case 16:
			op += "	list_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 17:
			if (record_1.length != 0) {
				op += "	list_" + std::to_string(current) + ".front();\n"; //Accesses the first element of the vector
			}
			break;
		case 19:
			if (record_1.length != 0) {
				op += "	list_" + std::to_string(current) + ".back();\n"; //Accesses the last element of the vector
			}
			break;
		case 20:
			op += "	list_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			break;
		case 21:
			op += "	list_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			break;
		case 22:
			op += "	list_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 23:
			op += "	list_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 24:
			op += "	list_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 25:
			op += "	list_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 26:
			op += "	list_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 27:
			op += "	list_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;


		}

	}



	records = local_records;
	return { op,records };
}

std::string random_list_loop(int number_of_index, std::vector<list_records> records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
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
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_list_" + std::to_string(m) + " = list_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_list_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_list_" + std::to_string(m) + " > " + generate_list_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_list_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_list_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_list_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_list_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_list_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_list_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	index_list_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}



std::tuple<std::string, std::string, std::vector<list_records>> create_list(int index) {
	std::string code;
	std::string oss;
	std::string type;
	int times = random_Int(1, 10);
	int list_elements_num = random_Int(5, 10);
	int list_rows = 2;// 1 for 1D vector
	std::list<int> temp_int = {};
	std::list<float> temp_float = {};
	std::list<double> temp_double = {};
	std::list<char> temp_char = {};
	std::list<bool> temp_bool = {};
	std::list<unsigned int> temp_uint = {};
	std::list<short> temp_short = {};
	std::list<unsigned short> temp_ushort = {};
	std::list<unsigned char> temp_uchar = {};
	std::list<long> temp_long = {};
	std::list<unsigned long> temp_ulong = {};


	//temp 2D sets
	std::list<std::list<int>> temp_2d_int;
	std::list<std::list<double>> temp_2d_double;
	std::list<std::list<char>> temp_2d_char;
	std::list<std::list<bool>> temp_2d_bool;
	std::list<std::list<float>> temp_2d_float;

	std::vector<list_records> list_records;


	aval_Type data_type = NONE;

	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();

		if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D or data_type == BOOL_2D) {
			//if (data_type == INT_2D or data_type == DOUBLE_2D or data_type == CHAR_2D or data_type == FLOAT_2D)
			list_records.push_back({ list_rows, type });
			//else
			//	list_records.push_back({ 1, type });

			for (int m = 1; m <= list_rows; m++) {

				switch (data_type) {
				case INT_2D: //int
					temp_int = create_list_int(list_elements_num);

					break;
				case FLOAT_2D: //float
					temp_float = create_list_float(list_elements_num);
					break;
				case DOUBLE_2D: //double
					temp_double = create_list_double(list_elements_num);
					break;
				case CHAR_2D: //char
					temp_char = create_list_char(list_elements_num);
					break;
				case BOOL_2D: //bool
					temp_bool = create_list_bool(list_elements_num);
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
					if (m < list_rows) {
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
					if (m < list_rows) {
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
					if (m < list_rows) {
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
					if (m < list_rows) {
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
					if (m < list_rows) {
						oss += "}, {";
					}
					else {
						oss += "}";
					}
					temp_bool = {};
				}


			}
			code += "	std::list<" + type + "> list_" + std::to_string(n) + " = { {" + oss + " };\n";
			oss = {};

		}


		else {
			int temp_size = 0;
			switch (data_type) {
			case INT:
				temp_int = create_list_int(list_elements_num);
				temp_size = temp_int.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_int);

				temp_int = {};
				break;

			case FLOAT:
				temp_float = create_list_float(list_elements_num);
				temp_size = temp_float.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_float);

				temp_float = {};
				break;

			case DOUBLE:
				temp_double = create_list_double(list_elements_num);
				temp_size = temp_double.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_double);

				temp_double = {};
				break;

			case CHAR:
				temp_char = create_list_char(list_elements_num);
				temp_size = temp_char.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_char);

				temp_char = {};
				break;

			case BOOL:
				temp_bool = create_list_bool(list_elements_num);
				temp_size = temp_bool.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_bool);
				temp_bool = {};
				break;
			case UCHAR:
				temp_uchar = create_list_uchar(list_elements_num);
				temp_size = temp_uchar.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_uchar);
				temp_uchar = {};
				break;
			case USHORT:
				temp_ushort = create_list_ushort(list_elements_num);
				temp_size = temp_ushort.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_ushort);
				temp_ushort = {};
				break;
			case SHORT:
				temp_short = create_list_short(list_elements_num);
				temp_size = temp_short.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_short);
				temp_short = {};
				break;
			case UINT:
				temp_uint = create_list_uint(list_elements_num);
				temp_size = temp_uint.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_uint);
				temp_uint = {};
				break;
			case ULONG:
				temp_ulong = create_list_ulong(list_elements_num);
				temp_size = temp_ulong.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_ulong);
				temp_ulong = {};
				break;
			case LONG:
				temp_long = create_list_long(list_elements_num);
				temp_size = temp_long.size();
				list_records.push_back({ temp_size, type });
				oss += list_to_string(temp_long);
				temp_long = {};
				break;

			}


			//print out secton

			switch (random_Int(1,1)) {
			case 1:
				code += "	std::list<" + type + "> list_" + std::to_string(n) + " = {" + oss + "};\n";
				break;
			case 2:
				code += "	std::list<" + type + "> list_" + std::to_string(n) + "(" + std::to_string(list_elements_num) + "," + generate_list_element(type) + ");\n";
				break;
			}
			oss = {};

		}

	}
	auto list_init = code;
	code.clear();
	auto output_record = list_records;
	//random operations generated
	auto [temp_string, temp_records] = random_list_op(index, list_records);
	code += temp_string;
	list_records = temp_records;

	code += random_list_loop(index, list_records, 1);

	//code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + list_records[m].type + "> newlist_" + std::to_string(m) + "(list_" + std::to_string(m) + ".begin(), list_" + std::to_string(m) + ".end());\n";
		code += "	append_data(buffer, newlist_" + std::to_string(m) + ");\n";

	}

	code += "\n";

	//for (const auto& record : list_records) {
	//	std::cout << "Length: " << record.length
	//		<< ", Type: " << record.type << std::endl;
	//}


	return { list_init,code,output_record };


}
