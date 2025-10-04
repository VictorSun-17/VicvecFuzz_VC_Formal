#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <string>
#include "Random_program.h"
#include <sstream>

std::string generate_map_element(std::string type_1, std::string type_2) {
	std::string op;
	int vec_elements_num = random_Int(5, 10);
	op += "{";
	if (type_1 == "int")
		op += std::to_string(random_Int(-100, 100));
	else if (type_1 == "float")
		op += std::to_string(random_Float(-100, 100));
	else if (type_1 == "double")
		op += std::to_string(random_Double(-100, 100));
	else if (type_1 == "char")
		op += std::to_string(random_Char());
	else if (type_1 == "bool")
		op += std::to_string(random_Bool());
	else if (type_1 == "unsigned int")
		op += std::to_string(random_UInt(0, 100));
	else if (type_1 == "unsigned char")
		op += std::to_string(random_UChar());
	else if (type_1 == "short")
		op += std::to_string(random_Short(100, 100));
	else if (type_1 == "unsigned short")
		op += std::to_string(random_UShort(0, 100));
	else if (type_1 == "long")
		op += std::to_string(random_Long(-100, 100));
	else if (type_1 == "unsigned long")
		op += std::to_string(random_ULong(0, 100));

	op += ",";

	if (type_2 == "int")
		op += std::to_string(random_Int(-100, 100));
	else if (type_2 == "float")
		op += std::to_string(random_Float(-100, 100));
	else if (type_2 == "double")
		op += std::to_string(random_Double(-100, 100));
	else if (type_2 == "char")
		op += std::to_string(random_Char());
	else if (type_2 == "bool")
		op += std::to_string(random_Bool());
	else if (type_2 == "unsigned int")
		op += std::to_string(random_UInt(0, 100));
	else if (type_2 == "unsigned char")
		op += std::to_string(random_UChar());
	else if (type_2 == "short")
		op += std::to_string(random_Short(100, 100));
	else if (type_2 == "unsigned short")
		op += std::to_string(random_UShort(0, 100));
	else if (type_2 == "long")
		op += std::to_string(random_Long(-100, 100));
	else if (type_2 == "unsigned long")
		op += std::to_string(random_ULong(0, 100));

	op += "}";

	return op;
}

std::string generate_key_element(std::string type) {
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

std::string generate_value_element(std::string type) {
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


std::vector<map_records> merge_records_min_length(
	const std::vector<map_records>& records1,
	const std::vector<map_records>& records2
) {
	std::vector<map_records> merged;
	size_t size = std::min(records1.size(), records2.size());
	merged.reserve(size);

	for (size_t i = 0; i < size; ++i) {
		map_records merged_record;
		merged_record.type_1 = records1[i].type_1; // 你也可以选择 records2[i].type 或做一致性判断
		merged_record.type_2 = records1[i].type_2;
		merged_record.length = std::min(records1[i].length, records2[i].length);
		merged.push_back(merged_record);
	}

	return merged;
}



std::pair<std::string, std::vector<map_records>> random_map_op(int n, std::vector<map_records> records, int operation_numbers = 10, int loop_index = 1) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<map_records> local_records = records;
	int random_size = random_Int(0, 19);

	//移出所有已生成函数的rdm

	for (int m = 1; m <= operation_numbers; m++) {
		current = random_Int(0, n - 1);
		current_2 = random_Int(0, n - 1);
		auto record_1 = local_records.at(current);
		auto record_2 = local_records.at(current_2);
		int tmp_length;
		int tmp_length_2;
		switch (random_Int(1, 25)) {

		case 1:
			if (record_1.type_1 != "bool" and record_1.length < 20 ) {
				op += "	map_" + std::to_string(current) + ".insert(" + generate_map_element(record_1.type_1, record_1.type_2) + "); \n"; //insert at certain place
				local_records[current].length += 1* loop_index;
			}
			break;
		case 2:
			op += "	map_" + std::to_string(current) + ".count(" + generate_key_element(record_1.type_1) + "); \n";
		case 3:
			if (record_1.length != 0) {
				op += "	map_" + std::to_string(current) + ".equal_range(" + generate_key_element(record_1.type_1) + "); \n";
			}
		case 4:
			if (record_1.length != 0) {
				op += "	auto map_it_" + std::to_string(m) + " = next(map_"+ std::to_string(current) +".begin()," + std::to_string(random_Int(0, record_1.length - 1)) + "); \n";
				op += "	map_" + std::to_string(current) + ".erase(map_it_" + std::to_string(m) + "); \n";
				local_records[current].length -= 1* loop_index;
			}
			break;
		case 5:
			if (record_1.length != 0) {
				op += "	map_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			}
			break;
		case 6:
			if (record_1.length != 0) {
				op += "	map_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			}
			break;
		case 7:
			op += "	map_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 8:
			op += "	map_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 9:
			op += "	map_" + std::to_string(current) + ".find(" + generate_key_element(record_1.type_1) + "); \n";
			break;
		case 10:
			op += "	map_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 11:
			op += "	map_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 12:
			op += "	map_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 13:
			op += "	map_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;

		case 14:

			if (record_1.length < 20) {

				op += "	map_" + std::to_string(current) + ".emplace(" + generate_key_element(record_1.type_1) + "," + generate_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

			}
			if (record_1.type_1 != "bool" /*or record_1.type_1 == "bool"*/)
				local_records[current].length += 1* loop_index;
			break;

		case 15:
			op += "	map_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;

		case 16:
			op += "	auto map_ithigh_" + std::to_string(m) + " = map_" + std::to_string(current) + ".upper_bound(" + generate_key_element(record_1.type_1) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 17:
			op += "	auto map_itlow_" + std::to_string(m) + " = map_" + std::to_string(current) + ".lower_bound(" + generate_key_element(record_1.type_1) + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 18: //TODO: Errors with emplace_hint function in VC Formal

		//	if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" or record_1.type_1 == "bool") {

		//		op += "	map_" + std::to_string(current) + ".emplace_hint(map_"+ std::to_string(current)+".begin() " +"," + generate_key_element(record_1.type_1) +"," + generate_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

		//	}
		//	if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" /*or record_1.type_1 == "bool"*/)
		//		local_records[current].length += 1;
			break;

		case 19:
			op += "	auto map_comp_" + std::to_string(m) + " = map_" + std::to_string(current) + ".value_comp();\n"; //The comparison object.
			break;
		case 20:
			op += "	auto map_comp_" + std::to_string(m) + " = map_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
			break;
		case 21:
			op += "	map_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 22:
			op += "	map_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 23:
			op += "	map_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			break;
		case 24:
			if (record_1.length != 0) {
				//op += "	map_" + std::to_string(current) + ".at(" + generate_key_element(record_1.type_1) + "); \n"; //Accesses the element at a specific position, with bounds checking.
			}
			break;
		case 25:
			if (record_1.type_1 == record_2.type_1 && record_1.type_2 == record_2.type_2 && current != current_2) {
				op += "	map_" + std::to_string(current) + ".swap(map_" + std::to_string(current_2) + ");\n"; // Swap two vectors
				tmp_length = local_records[current].length;
				tmp_length_2 = local_records[current_2].length;
				local_records[current].length = tmp_length_2;
				local_records[current_2].length = tmp_length;
			}
			break;





		}

	}



	records = local_records;
	return { op,records };
}



std::string random_map_loop(int number_of_index, std::vector<map_records> records, int operation_loop_numbers = random_Int(5, 5)) {
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
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second > " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second < " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second <= " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second >= " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second == " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 6:
			// multiple layer of if/else：insert/replace element
			if (record_1.length > 0) {
				int idx = random_Int(0, record_1.length - 1);
				op += "	auto index_map_" + std::to_string(m) + " = map_" + std::to_string(current) + ".begin();\n";
				op += "	std::advance(index_map_" + std::to_string(m) + ", " + std::to_string(idx) + ");\n";
				op += "	if ( index_map_" + std::to_string(m) + "->second != " + generate_value_element(record_1.type_2) + ") {\n";
				auto [temp_string_1, temp_records_1] = random_map_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto [temp_string_2, temp_records_2] = random_map_op(number_of_index, records, random_Int(0, 5));
				records = merge_records_min_length(temp_records_1, temp_records_2);
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		//case 7:
		//	if (record_1.length > for_loop_size) {
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		auto [temp_string, temp_records] = random_map_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	}\n";
		//	}
		//	break;

		//case 8:
		//	if (record_1.length > for_loop_size) {
		//		op += "	int index_map_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_map_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		auto [temp_string, temp_records] = random_map_op(number_of_index, records, 1, for_loop_size);
		//		records = temp_records;
		//		op += temp_string;
		//		op += "	index_map_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	}
		//	break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}



std::tuple<std::string, std::string, std::vector<map_records>> create_map(int index) {
	std::string code;
	std::string oss;
	std::string type_1;
	std::string type_2;
	int map_elements_num = random_Int(5, 10);
	/*int vec_rows = random_Int(1, 2);*/
	int map_rows = 2;// 1 for 1D vector
	int temp_length = 0;
	//temp vectors
	std::vector<int> temp_int_2 = {};
	std::vector<float> temp_float_2 = {};
	std::vector<double> temp_double_2 = {};
	std::vector<char> temp_char_2 = {};
	std::vector<bool> temp_bool_2 = {};
	std::vector<unsigned int> temp_uint_2 = {};
	std::vector<short> temp_short_2 = {};
	std::vector<unsigned short> temp_ushort_2 = {};
	std::vector<unsigned char> temp_uchar_2 = {};
	std::vector<long> temp_long_2 = {};
	std::vector<unsigned long> temp_ulong_2 = {};

	std::vector<int> temp_int_1 = {};
	std::vector<float> temp_float_1 = {};
	std::vector<double> temp_double_1 = {};
	std::vector<char> temp_char_1 = {};
	std::vector<bool> temp_bool_1 = {};
	std::vector<unsigned int> temp_uint_1 = {};
	std::vector<short> temp_short_1 = {};
	std::vector<unsigned short> temp_ushort_1 = {};
	std::vector<unsigned char> temp_uchar_1 = {};
	std::vector<long> temp_long_1 = {};
	std::vector<unsigned long> temp_ulong_1 = {};

	std::set<int> temp_set_int = {};
	std::set<float> temp_set_float = {};
	std::set<double> temp_set_double = {};
	std::set<char> temp_set_char = {};
	std::set<bool> temp_set_bool = {};
	std::set<unsigned int> temp_set_uint = {};
	std::set<short> temp_set_short = {};
	std::set<unsigned short> temp_set_ushort = {};
	std::set<unsigned char> temp_set_uchar = {};
	std::set<long> temp_set_long = {};
	std::set<unsigned long> temp_set_ulong = {};

	std::vector<map_records> map_records;





	for (int n = 0; n < index; n++) {


		auto [data_type_1, type_1] = random_type();

		auto [data_type_2, type_2] = random_type();



		//vec_records.push_back({ vec_elements_num, type });





		if (type_1 == "int") {
			temp_int_1 = create_vec_int(map_elements_num);
			temp_set_int.insert(temp_int_1.begin(), temp_int_1.end());
			temp_length = temp_set_int.size();
		}
		else if (type_1 == "float") {
			temp_float_1 = create_vec_float(map_elements_num);
			temp_set_float.insert(temp_float_1.begin(), temp_float_1.end());
			temp_length = temp_set_float.size();
		}
		else if (type_1 == "double")
		{
			temp_double_1 = create_vec_double(map_elements_num);
			temp_set_double.insert(temp_double_1.begin(), temp_double_1.end());
			temp_length = temp_set_double.size();
		}
		else if (type_1 == "char") {
			temp_char_1 = create_vec_char(map_elements_num);
			temp_set_char.insert(temp_char_1.begin(), temp_char_1.end());
			temp_length = temp_set_char.size();
		}
		else if (type_1 == "bool") {
			temp_bool_1 = create_vec_bool(map_elements_num);
			temp_set_bool.insert(temp_bool_1.begin(), temp_bool_1.end());
			temp_length = temp_set_bool.size();
		}
		else if (type_1 == "unsigned char") {
			temp_uchar_1 = create_vec_uchar(map_elements_num);
			temp_set_uchar.insert(temp_uchar_1.begin(), temp_uchar_1.end());
			temp_length = temp_set_uchar.size();
		}
		else if (type_1 == "short")
		{
			temp_short_1 = create_vec_short(map_elements_num);
			temp_set_short.insert(temp_short_1.begin(), temp_short_1.end());
			temp_length = temp_set_short.size();
		}
		else if (type_1 == "unsigned short") {
			temp_ushort_1 = create_vec_ushort(map_elements_num);
			temp_set_ushort.insert(temp_ushort_1.begin(), temp_ushort_1.end());
			temp_length = temp_set_ushort.size();
		}
		else if (type_1 == "unsigned int") {
			temp_uint_1 = create_vec_uint(map_elements_num);
			temp_set_uint.insert(temp_uint_1.begin(), temp_uint_1.end());
			temp_length = temp_set_uint.size();
		}
		else if (type_1 == "long") {
			temp_long_1 = create_vec_long(map_elements_num);
			temp_set_long.insert(temp_long_1.begin(), temp_long_1.end());
			temp_length = temp_set_long.size();
		}
		else if (type_1 == "unsigned long") {
			temp_ulong_1 = create_vec_ulong(map_elements_num);
			temp_set_ulong.insert(temp_ulong_1.begin(), temp_ulong_1.end());
			temp_length = temp_set_ulong.size();
		}

		if (type_2 == "int") {
			temp_int_2 = create_vec_int(map_elements_num);
		}
		else if (type_2 == "float") {
			temp_float_2 = create_vec_float(map_elements_num);
		}
		else if (type_2 == "double")
		{
			temp_double_2 = create_vec_double(map_elements_num);
		}
		else if (type_2 == "char") {
			temp_char_2 = create_vec_char(map_elements_num);
		}
		else if (type_2 == "bool") {
			temp_bool_2 = create_vec_bool(map_elements_num);
		}
		else if (type_2 == "unsigned char") {
			temp_uchar_2 = create_vec_uchar(map_elements_num);
		}
		else if (type_2 == "short")
		{
			temp_short_2 = create_vec_short(map_elements_num);
		}
		else if (type_2 == "unsigned short") {
			temp_ushort_2 = create_vec_ushort(map_elements_num);
		}
		else if (type_2 == "unsigned int") {
			temp_uint_2 = create_vec_uint(map_elements_num);
		}
		else if (type_2 == "long") {
			temp_long_2 = create_vec_long(map_elements_num);
		}
		else if (type_2 == "unsigned long") {
			temp_ulong_2 = create_vec_ulong(map_elements_num);
		}


		map_records.push_back({ temp_length, type_1,type_2 });



		for (int i = 1; i <= temp_length; i++) {
			oss += "{";
			if (type_1 == "int") {
				auto it = temp_set_int.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "float") {
				auto it = temp_set_float.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "double") {
				auto it = temp_set_double.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "char") {
				auto it = temp_set_char.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "bool")
			{
				auto it = temp_set_bool.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "unsigned char") {
				auto it = temp_set_uchar.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "short")
			{
				auto it = temp_set_short.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "unsigned short") {
				auto it = temp_set_ushort.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "unsigned int") {
				auto it = temp_set_uint.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "long") {
				auto it = temp_set_long.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}
			else if (type_1 == "unsigned long") {
				auto it = temp_set_ulong.begin();
				advance(it, i - 1);
				auto value = *it;
				oss += std::to_string(value);
			}

			oss += ",";
			
			if (type_2 == "int")
				oss += std::to_string(temp_int_2[i - 1]);
			else if (type_2 == "float")
				oss += std::to_string(temp_float_2[i - 1]);
			else if (type_2 == "double")
				oss += std::to_string(temp_double_2[i - 1]);
			else if (type_2 == "char")
				oss += std::to_string(temp_char_2[i - 1]);
			else if (type_2 == "bool")
				oss += std::to_string(temp_bool_2[i - 1]);
			else if (type_2 == "unsigned char") 
				oss += std::to_string(temp_uchar_2[i - 1]);
			else if (type_2 == "short")
				oss += std::to_string(temp_short_2[i - 1]);
			else if (type_2 == "unsigned short") 				
				oss += std::to_string(temp_ushort_2[i - 1]);
			else if (type_2 == "unsigned int") 
				oss += std::to_string(temp_uint_2[i - 1]);
			else if (type_2 == "long") 				
				oss += std::to_string(temp_long_2[i - 1]);
			else if (type_2 == "unsigned long") 				
				oss += std::to_string(temp_ulong_2[i - 1]);
			oss += "}";
			if (i != temp_length) {
				oss += ", "; // Add a separator between numbers
			}
		}

		temp_bool_1 = {};
		temp_char_1 = {};
		temp_float_1 = {};
		temp_int_1 = {};
		temp_double_1 = {};
		temp_bool_2 = {};
		temp_char_2 = {};
		temp_float_2 = {};
		temp_int_2 = {};
		temp_double_2 = {};
		temp_set_int = {};
		temp_set_float = {};
		temp_set_double = {};
		temp_set_char = {};
		temp_set_bool = {};
		temp_length = 0;


		code += "	std::map<" + type_1 + "," + type_2 + "> map_" + std::to_string(n) + " = {" + oss + "};\n";
		oss = {};



	}
	auto map_init = code;
	code.clear();
	auto output_record = map_records;
	//random operations generated

	auto [temp_string, temp_records] = random_map_op(index, map_records);
	code += temp_string;
	map_records = temp_records;

	code += random_map_loop(index, map_records, 1);

	for (int m = 0; m < index; m++) {
		code += "	std::pair<std::vector<" + map_records[m].type_1 + ">,std::vector<" + map_records[m].type_2 + ">> newmap_" + std::to_string(m) + " = map_to_vectors(map_" + std::to_string(m) + ");\n";
		code += "	append_data(buffer, newmap_" + std::to_string(m) + ".first);\n";
		code += "	append_data(buffer, newmap_" + std::to_string(m) + ".second);\n";
	}




	code += "\n";
	return { map_init, code, output_record };
}
