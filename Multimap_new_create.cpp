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
#include <algorithm>  

template <typename T>
std::vector<std::string> multimap_key_to_string(const std::vector<T>& vec) {
	std::vector<std::string> result;
	result.reserve(vec.size());

	for (const auto& val : vec) {
		if constexpr (std::is_arithmetic_v<T>) {
			// 数值类型直接用 std::to_string
			result.push_back(std::to_string(val));
		}
		else {
			// 其他类型用输出流转换
			std::ostringstream oss;
			oss << val;
			result.push_back(oss.str());
		}
	}

	return result;
}

std::string multimap_to_string(std::vector<std::string> key, std::vector<std::string> value) {
	std::string oss;
	int elements_num = key.size();
	for (int i = 1; i <= elements_num; i++) {
		oss += "{" + key[i - 1] + "," + value[i - 1] + "}";
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}


std::string generate_multi_element(std::string type) {
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


std::tuple<std::string, std::vector<multimap_records>, std::vector<std::string>> random_multimap_op(int n, std::vector<multimap_records> records, std::vector<std::string> current_key_value, int operation_numbers = 5, int loop_index = 1, int loop_mode = 0) {
	std::vector<std::string> temp_key_record = current_key_value;
	std::string op;
	int current_length = 0;
	int current = n;
	//int current_2 = 0;
	std::vector<multimap_records> local_records = records;

	for (int m = 1; m <= operation_numbers; m++) {

		auto record_1 = local_records.at(n);

		current_length = temp_key_record.size();
		std::string key = generate_multi_element(record_1.type_1);
		std::string value = generate_multi_element(record_1.type_2);


		int random_index_erase = random_Int(0, current_length - 1);

		switch (random_Int(1, 23)) {

		case 1:
			if (record_1.length < 20) {

				op += "	multimap_" + std::to_string(current) + ".insert({" + key + "," + value + "}); \n"; //insert at certain place
				temp_key_record.push_back(key);

				local_records[current].length += 1 * loop_index;
			}
			break;
		case 2:
			op += "	multimap_" + std::to_string(current) + ".count(" + key + "); \n";
		case 3:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".equal_range(" + key + "); \n";
			}
		case 4: //erase 逻辑需要重建
			if (current_length != 0) {
				temp_key_record.erase(
					std::remove(temp_key_record.begin(), temp_key_record.end(), key),
					temp_key_record.end()
				);
				op += "	multimap_" + std::to_string(current) + ".erase(" + key + "); \n";
				local_records[current].length -= 1 * loop_index;
			}
			break;
		case 5:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".begin();\n"; //Returns an iterator pointing to the first element of the vector
			}
			break;
		case 6:
			if (current_length != 0) {
				op += "	multimap_" + std::to_string(current) + ".end();\n"; // Returns an iterator pointing to the past-the-end element of the vector
			}
			break;
		case 7:
			op += "	multimap_" + std::to_string(current) + ".rbegin();\n"; //Returns a reverse iterator pointing to the last element of the vector
			break;
		case 8:
			op += "	multimap_" + std::to_string(current) + ".rend();\n"; // Returns a reverse iterator pointing to the element preceding the first element of the vector
			break;
		case 9:
			op += "	multimap_" + std::to_string(current) + ".find(" + key + "); \n";
			break;
		case 10:
			op += "	multimap_" + std::to_string(current) + ".cbegin();\n"; //Returns const_iterator to beginning
			break;
		case 11:
			op += "	multimap_" + std::to_string(current) + ".cend();\n"; // Returns const_iterator to end
			break;
		case 12:
			op += "	multimap_" + std::to_string(current) + ".crbegin();\n"; //Returns const_reverse_iterator to reverse beginning
			break;
		case 13:
			op += "	multimap_" + std::to_string(current) + ".crend();\n"; // Returns const_reverse_iterator to reverse end
			break;

		case 14:
			if (record_1.length < 20) {

				op += "	multimap_" + std::to_string(current) + ".emplace(" + key + "," + value + "); \n"; //insert at certain place
				temp_key_record.push_back(key);
				local_records[current].length += 1 * loop_index;
			}
			break;

		case 15:
			op += "	multimap_" + std::to_string(current) + ".max_size();\n"; //Returns the maximum number of elements that the vector can hold.
			break;

		case 16:
			op += "	auto multi_ithigh_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".upper_bound(" + key + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 17:
			op += "	auto multi_itlow_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".lower_bound(" + key + ");\n";
			//An iterator to the the first element in the container which is considered to go after val, or set::end if no elements are considered to go after val.
			break;
		case 18:

			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" or record_1.type_1 == "bool") {

			//	op += "	multimap_" + std::to_string(current) + ".emplace_hint(multimap_" + std::to_string(current) + ".begin() " + "," + generate_multi_key_element(record_1.type_1) + "," + generate_multi_value_element(record_1.type_2) + "); \n"; // Constructs and inserts an element in the vector.

			//}
			//if (record_1.type_1 == "int" or record_1.type_1 == "double" or record_1.type_1 == "char" or record_1.type_1 == "float" /*or record_1.type_1 == "bool"*/)
			//	local_records[current].length += 1;
			break;

		case 19:
			op += "	auto mymulti_comp_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".value_comp();\n"; //The comparison object.
			break;
		case 20:
			op += "	auto mymulti_comp_" + std::to_string(n) + std::to_string(m) + std::to_string(loop_mode) + " = multimap_" + std::to_string(current) + ".key_comp();\n"; //The comparison object.
			break;
		case 21:
			op += "	multimap_" + std::to_string(current) + ".size();\n"; //Returns the number of elements in the vector.
			break;
		case 22:
			op += "	multimap_" + std::to_string(current) + ".empty();\n"; //Checks if the vector is empty.
			break;
		case 23:
			op += "	multimap_" + std::to_string(current) + ".clear();\n";
			local_records[current].length = 0;
			temp_key_record.clear();
			break;
		}

		local_records[current].length = temp_key_record.size();
	}



	records = local_records;
	return { op,records, temp_key_record };
}



std::tuple<std::string, std::string, std::vector<multimap_records>> create_multimap(int index) {
	std::string code;
	std::string oss;
	std::string type_1;
	std::string type_2;

	std::string multimap_init;
	std::vector<multimap_records> output_record;

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

	std::vector<std::string> current_key_record = {};
	std::vector<std::string> current_value_record = {};

	std::vector<multimap_records> map_records;


	for (int n = 0; n < index; n++) {

		auto [data_type_1, type_1] = random_type();

		auto [data_type_2, type_2] = random_type();



		//vec_records.push_back({ vec_elements_num, type });





		if (type_1 == "int") {
			temp_int_1 = create_vec_int(map_elements_num);
			temp_length = temp_int_1.size();
			current_key_record = multimap_key_to_string(temp_int_1);
		}
		else if (type_1 == "float") {
			temp_float_1 = create_vec_float(map_elements_num);
			temp_length = temp_float_1.size();
			current_key_record = multimap_key_to_string(temp_float_1);
		}
		else if (type_1 == "double")
		{
			temp_double_1 = create_vec_double(map_elements_num);
			temp_length = temp_double_1.size();
			current_key_record = multimap_key_to_string(temp_double_1);
		}
		else if (type_1 == "char") {
			temp_char_1 = create_vec_char(map_elements_num);
			temp_length = temp_char_1.size();
			current_key_record = multimap_key_to_string(temp_char_1);
		}
		else if (type_1 == "bool") {
			temp_bool_1 = create_vec_bool(map_elements_num);
			temp_length = temp_bool_1.size();
			current_key_record = multimap_key_to_string(temp_bool_1);
		}
		else if (type_1 == "unsigned int") {
			temp_uint_1 = create_vec_uint(map_elements_num);
			temp_length = temp_uint_1.size();
			current_key_record = multimap_key_to_string(temp_uint_1);
		}
		else if (type_1 == "short") {
			temp_short_1 = create_vec_short(map_elements_num);
			temp_length = temp_short_1.size();
			current_key_record = multimap_key_to_string(temp_short_1);
		}
		else if (type_1 == "unsigned short")
		{
			temp_ushort_1 = create_vec_ushort(map_elements_num);
			temp_length = temp_ushort_1.size();
			current_key_record = multimap_key_to_string(temp_ushort_1);
		}
		else if (type_1 == "unsigned char") {
			temp_uchar_1 = create_vec_uchar(map_elements_num);
			temp_length = temp_uchar_1.size();
			current_key_record = multimap_key_to_string(temp_uchar_1);
		}
		else if (type_1 == "long") {
			temp_long_1 = create_vec_long(map_elements_num);
			temp_length = temp_long_1.size();
			current_key_record = multimap_key_to_string(temp_long_1);
		}
		else if (type_1 == "unsigned long") {
			temp_ulong_1 = create_vec_ulong(map_elements_num);
			temp_length = temp_ulong_1.size();
			current_key_record = multimap_key_to_string(temp_ulong_1);
		}

		if (type_2 == "int") {
			temp_int_2 = create_vec_int(map_elements_num);
			current_value_record = multimap_key_to_string(temp_int_2);
		}
		else if (type_2 == "float") {
			temp_float_2 = create_vec_float(map_elements_num);
			current_value_record = multimap_key_to_string(temp_float_2);
		}
		else if (type_2 == "double")
		{
			temp_double_2 = create_vec_double(map_elements_num);
			current_value_record = multimap_key_to_string(temp_double_2);
		}
		else if (type_2 == "char") {
			temp_char_2 = create_vec_char(map_elements_num);
			current_value_record = multimap_key_to_string(temp_char_2);
		}
		else if (type_2 == "bool") {
			temp_bool_2 = create_vec_bool(map_elements_num);
			current_value_record = multimap_key_to_string(temp_bool_2);
		}
		else if (type_2 == "unsigned int") {
			temp_uint_2 = create_vec_uint(map_elements_num);
			current_value_record = multimap_key_to_string(temp_uint_2);
		}
		else if (type_2 == "short") {
			temp_short_2 = create_vec_short(map_elements_num);
			current_value_record = multimap_key_to_string(temp_short_2);
		}
		else if (type_2 == "unsigned short")
		{
			temp_ushort_2 = create_vec_ushort(map_elements_num);
			current_value_record = multimap_key_to_string(temp_ushort_2);
		}
		else if (type_2 == "unsigned char") {
			temp_uchar_2 = create_vec_uchar(map_elements_num);
			current_value_record = multimap_key_to_string(temp_uchar_2);
		}
		else if (type_2 == "long") {
			temp_long_2 = create_vec_long(map_elements_num);
			current_value_record = multimap_key_to_string(temp_long_2);
		}
		else if (type_2 == "unsigned long") {
			temp_ulong_2 = create_vec_ulong(map_elements_num);
			current_value_record = multimap_key_to_string(temp_ulong_2);
		}



		map_records.push_back({ temp_length, type_1,type_2 });
		output_record.push_back({ temp_length, type_1,type_2 });

		oss += multimap_to_string(current_key_record, current_value_record);

		multimap_init += "	std::multimap<" + type_1 + "," + type_2 + "> multimap_" + std::to_string(n) + " = {" + oss + "};\n";
		oss = {};

		auto [temp_string, temp_records, temp_map] = random_multimap_op(n, map_records, current_key_record);
		code += temp_string;


		//clear all temporal containers
		temp_int_2 = {};
		temp_float_2 = {};
		temp_double_2 = {};
		temp_char_2 = {};
		temp_bool_2 = {};
		temp_uint_2 = {};
		temp_short_2 = {};
		temp_ushort_2 = {};
		temp_uchar_2 = {};
		temp_long_2 = {};
		temp_ulong_2 = {};

		temp_int_1 = {};
		temp_float_1 = {};
		temp_double_1 = {};
		temp_char_1 = {};
		temp_bool_1 = {};
		temp_uint_1 = {};
		temp_short_1 = {};
		temp_ushort_1 = {};
		temp_uchar_1 = {};
		temp_long_1 = {};
		temp_ulong_1 = {};

	}
	//code += all_op(index, map_records);
	for (int m = 0; m < index; m++) {
		code += "	std::pair<std::vector<" + map_records[m].type_1 + ">,std::vector<" + map_records[m].type_2 + ">> newmultimap_" + std::to_string(m) + " = map_to_vectors(multimap_" + std::to_string(m) + ");\n";
		code += "	append_data(buffer, newmultimap_" + std::to_string(m) + ".first);\n";
		code += "	append_data(buffer, newmultimap_" + std::to_string(m) + ".second);\n";
	}




	code += "\n";
	return { multimap_init,code, output_record };
}
