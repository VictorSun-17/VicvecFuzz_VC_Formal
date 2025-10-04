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
std::set<unsigned int> create_set_uint(int length = 1) {
	std::set<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_UInt(0, 100));
	}
	return temp;
}

std::set<short> create_set_short(int length = 1) {
	std::set<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Short(-100, 100));
	}

	return temp;
}

std::set<unsigned short> create_set_ushort(int length = 1) {
	std::set<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_UShort(0, 100));
	}

	return temp;
}

std::set<unsigned char> create_set_uchar(int length = 1) {
	std::set<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_UChar());
	}

	return temp;
}

std::set<long> create_set_long(int length = 1) {
	std::set<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_Long(-100, 100));
	}

	return temp;
}

std::set<unsigned long> create_set_ulong(int length = 1) {
	std::set<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.emplace(random_ULong(0, 100));
	}

	return temp;
}

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

std::vector<set_records> merge_records_min_length(
	const std::vector<set_records>& records1,
	const std::vector<set_records>& records2
) {
	std::vector<set_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		set_records merged_record;
		merged_record.type = records1[i].type; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}

std::pair<std::string, std::vector<set_records>> random_set_op(int n, std::vector<set_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
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
				op += "	set_" + std::to_string(current) + ".begin(); \n";//An iterator to the first element in the container.
			}
			break;
		case 2:
			if (record_1.length != 0) {
				op += "	set_" + std::to_string(current) + ".cbegin(); \n";//A const_iterator to the beginning of the sequence.
			}
			break;
		case 3:
			if (record_1.length != 0) {
				op += "	set_" + std::to_string(current) + ".cend(); \n";//A const_iterator to the element past the end of the sequence.
			}
			break;
		case 4:
			op += "	set_" + std::to_string(current) + ".clear(); \n";//clean all
			local_records[current].length = 0;
			break;
		case 5:
			op += "	set_" + std::to_string(current) + ".count(" + generate_set_element(record_1.type) + "); \n";//A const_iterator to the element past the end of the sequence.
			break;
		case 6:
			if (record_1.length != 0) {
				op += "	set_" + std::to_string(current) + ".crbegin(); \n";//A const_reverse_iterator to the reverse beginning of the sequence.
			}
			break;
		case 7:
			if (record_1.length != 0) {
				op += "	set_" + std::to_string(current) + ".crend(); \n";//A const_reverse_iterator to the reverse end of the sequence.
			}
			break;
		case 8:
			//TODO:need optimization
			if (record_1.type == "int" or record_1.type == "double" or record_1.type == "char" or record_1.type == "float" or record_1.type == "bool"
				or record_1.type == "unsigned int" or record_1.type == "unsigned short" or record_1.type == "unsigned char" or record_1.type == "short" or record_1.type == "long"
				or record_1.type == "unsigned long") {
				op += "	set_" + std::to_string(current) + ".emplace(" + generate_set_element(record_1.type) + "); \n";
			}
			else if (record_1.type == "std::vector<int>") 
				op += "	set_" + std::to_string(current) + ".emplace(std::set<int>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<float>")
				op += "	set_" + std::to_string(current) + ".emplace(std::set<float>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<double>")
				op += "	set_" + std::to_string(current) + ".emplace(std::set<double>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<char>")
				op += "	set_" + std::to_string(current) + ".emplace(std::set<char>" + generate_set_element(record_1.type) + "); \n";
			else if (record_1.type == "std::vector<bool>")
				op += "	set_" + std::to_string(current) + ".emplace(std::set<bool>" + generate_set_element(record_1.type) + "); \n";
			// If the function successfully inserts the element(because no equivalent element existed already in the set), 
			// the function returns a pair of an iterator to the newly inserted element and a value of true.
			if (record_1.type != "bool") {
				local_records[current].length += 1* loop_index;
				}
			break;
		case 9:
			//TODO: need optimization
			//op += "set_" + std::to_string(current) + ".emplace_hint(set_" + std::to_string(current) + ".find(" + std::to_string(random_Int(1, 100)) + ")," + std::to_string(random_Int(1, 100)) + "); \n";
			break;
		case 10:
			op += "	set_" + std::to_string(current) + ".empty(); \n";//true if the container size is 0, false otherwise.
			break;
		case 11:
			if (record_1.length != 0) {
				op += "	set_" + std::to_string(current) + ".end(); \n";//An iterator to the past-the-end element in the container.
			}
			break;
		case 12:
			op += "	auto range_" + std::to_string(m) + " = set_" + std::to_string(current) + ".equal_range(" + generate_set_element(record_1.type) + "); \n";
			//The function returns a pair, whose member pair::first is the lower bound of the range (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			break;
		case 13:
			if (record_1.length != 0) {
				op += "	auto it_"+std::to_string(m) + " = next(set_" + std::to_string(current) + ".begin(), " + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	set_" + std::to_string(current) + ".erase(it_" + std::to_string(m) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 14:
			op += "	auto it_" + std::to_string(m) + " = set_" + std::to_string(current) + ".find(" + generate_set_element(record_1.type) + ");\n"; //An iterator to the element, if val is found, or set::end otherwise.
			break;
		case 15:
			op += "	auto alloc_" + std::to_string(m) + " = set_" + std::to_string(current) + ".get_allocator();\n";//Member type allocator_type is the type of the allocator used by the container, defined in set as an alias of its third template parameter
			break;
		case 16:
			op += "	set_" + std::to_string(current) + ".insert(" + generate_set_element(record_1.type) + "); \n";//For the value-based version (2), the function returns the number of elements erased.
			if (record_1.type != "std::vector<bool>" and record_1.type != "bool") {
				local_records[current].length += 1 * loop_index;
			}
			break;
		case 17:
			op += "	auto mycomp_" + std::to_string(m) + " = set_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
			break;
		case 18:
			op += "	auto itlow_" + std::to_string(m) + " = set_" + std::to_string(current) + ".lower_bound(" + generate_set_element(record_1.type) + ");\n";
			//Returns an iterator pointing to the first element in the container which is not considered to go before val (i.e., either it is equivalent or goes after).
			break;
		case 19:
			op += "	set_" + std::to_string(current) + ".max_size();\n"; //The maximum number of elements a set container can hold as content.
			break;
		case 20:
			op += "	set_" + std::to_string(current) + ".rbegin();\n"; //A reverse iterator to the reverse beginning of the sequence container.
			break;
		case 21:
			op += "	set_" + std::to_string(current) + ".rend();\n"; //A reverse iterator to the reverse end of the sequence container.
			break;
		case 22:
			op += "	set_" + std::to_string(current) + ".size();\n"; //The number of elements in the container.
			break;
		case 23:
			if (record_1.type == record_2.type && current != current_2) {
				op += "	set_" + std::to_string(current) + ".swap(set_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;
		case 24:
			op += "	auto ithigh_" + std::to_string(m) + " = set_" + std::to_string(current) + ".upper_bound(" + generate_set_element(record_1.type) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		}



	}
	records = local_records;
	return { op,records };
}

std::string random_set_loop(int number_of_index, std::vector<set_records> set_records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = set_records.at(current);
		int for_loop_size = random_Int(0, 5);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " > " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " < " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " <= " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " >= " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " == " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_set_" + std::to_string(m) + " = set_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_set_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( *index_set_" + std::to_string(m) + " != " + generate_set_element(record_1.type) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_set_op(number_of_index, set_records, random_Int(0, 5));
				set_records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_set_op(number_of_index, set_records, 1, for_loop_size);
		//		set_records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_set_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_set_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_set_op(number_of_index, set_records, 1, for_loop_size);
		//		set_records = temp_records;
		//		op += temp_string;
		//		op += "	index_set_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}




std::tuple<std::string, std::string, std::vector<set_records>> create_set(int index) {
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
	std::set<unsigned int> temp_uint = {};
	std::set<short> temp_short = {};
	std::set<unsigned short> temp_ushort = {};
	std::set<unsigned char> temp_uchar = {};
	std::set<long> temp_long = {};
	std::set<unsigned long> temp_ulong = {};

	//temp 2D sets
	std::set<std::set<int>> temp_2d_int;
	std::set<std::set<double>> temp_2d_double;
	std::set<std::set<char>> temp_2d_char;
	std::set<std::set<bool>> temp_2d_bool;
	std::set<std::set<float>> temp_2d_float;

	std::vector<set_records> set_records;


	aval_Type data_type = NONE;

	for (int n = 0; n < index; n++) {

		auto [data_type, type] = random_type();

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
			int temp_size = 0;
			switch (data_type) {
			case INT:
				temp_int = create_set_int(set_elements_num);
				temp_size = temp_int.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_int);

				temp_int = {};
				break;

			case FLOAT:
				temp_float = create_set_float(set_elements_num);
				temp_size = temp_float.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_float);

				temp_float = {};
				break;

			case DOUBLE:
				temp_double = create_set_double(set_elements_num);
				temp_size = temp_double.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_double);

				temp_double = {};
				break;

			case CHAR:
				temp_char = create_set_char(set_elements_num);
				temp_size = temp_char.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_char);

				temp_char = {};
				break;

			case BOOL:
				temp_bool = create_set_bool(set_elements_num);
				temp_size = temp_bool.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_bool);
				temp_bool = {};
				break;
			case UCHAR:
				temp_uchar = create_set_uchar(set_elements_num);
				temp_size = temp_uchar.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_uchar);
				temp_uchar = {};
				break;
			case USHORT:
				temp_ushort = create_set_ushort(set_elements_num);
				temp_size = temp_ushort.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_ushort);
				temp_ushort = {};
				break;
			case SHORT:
				temp_short = create_set_short(set_elements_num);
				temp_size = temp_short.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_short);
				temp_short = {};
				break;
			case UINT:
				temp_uint = create_set_uint(set_elements_num);
				temp_size = temp_uint.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_uint);
				temp_uint = {};
				break;
			case ULONG:
				temp_ulong = create_set_ulong(set_elements_num);
				temp_size = temp_ulong.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_ulong);
				temp_ulong = {};
				break;
			case LONG:
				temp_long = create_set_long(set_elements_num);
				temp_size = temp_long.size();
				set_records.push_back({ temp_size, type });
				oss += set_to_string(temp_long);
				temp_long = {};
				break;

			}

			code += "	std::set<" + type + "> set_" + std::to_string(n) + " = {" + oss + "};\n";
			oss = {};

		}

	}

	auto set_init = code;
	code.clear();
	auto output_record = set_records;
	//random operations generated
	for (const auto& rec : set_records) {
		std::cout << "Set Length: " << rec.length
			<< "Set Type: " << rec.type << std::endl;
	}

	auto [temp_string, temp_records] = random_set_op(index, set_records);
	code += temp_string;
	set_records = temp_records;

	code += random_set_loop(index, set_records, 1);

	//code += "	std::vector<uint8_t> buffer;\n";
	for (int m = 0; m < index; m++) {
		code += "	std::vector<" + set_records[m].type + "> newset_" + std::to_string(m) + ";\n";
		code += "   for (auto& elem_" + std::to_string(m) + " : set_" + std::to_string(m) + ") {\n";
		code += "   		newset_" + std::to_string(m) + ".push_back(elem_" + std::to_string(m) + ");\n";
		code += "    }\n";
		code += "	append_data(buffer, newset_" + std::to_string(m) + ");\n";

	} 

	code += "\n";

	return {set_init,code,set_records};


}
