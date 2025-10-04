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
#include <stack>
#include <cmath>

int create_bitset_int(int length = 1) {
	int temp = random_Int(0, pow(2, length) - 1);
	return temp;
}


struct bitset_records {
	int length;
};


std::string random_bitset_op(int n, std::vector<bitset_records> records, int operation_numbers = 5) {
	std::string op;
	int current = 0;
	int current_2 = 0;
	std::vector<bitset_records> local_records = records;
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
			op += "	bitset_" + std::to_string(current) + ".set(); \n";//Adds an element to the end of the vector.
			break;
		case 2:
			op += "	bitset_" + std::to_string(current) + ".reset(); \n";
			break;
		case 3:
			if (record_1.length != 0) {
				op += "	bitset_" + std::to_string(current) + ".flip(" + std::to_string(random_Int(0, record_1.length - 1)) + ");\n";
			}
			break;
		case 4:
			op += "	bitset_" + std::to_string(current) + ".count(); \n";//Adds an element to the end of the vector.
			break;
		case 5:
			op += "	bitset_" + std::to_string(current) + ".test(" + std::to_string(random_Int(0, record_1.length - 1)) + ");\n";
			break;
		case 6:
			op += "	bitset_" + std::to_string(current) + ".any();\n";
			break;
		case 7:
			op += "	bitset_" + std::to_string(current) + ".none();\n";
			break;
		case 8:
			op += "	bitset_" + std::to_string(current) + ".all();\n";
			break;
		case 9:
			op += "	bitset_" + std::to_string(current) + ".size();\n";
			break;


		}
	}




	return op;
}

std::string random_bitset_loop(int number_of_index, std::vector<bitset_records> records, int operation_loop_numbers = random_Int(5, 5)) {
	std::string op;
	//std::vector<vector_records> local_records = vec_records;
	int current = 0;
	for (int m = 1; m <= operation_loop_numbers; m++) {
		current = random_Int(0, number_of_index - 1);
		auto record_1 = records.at(current);
		int for_loop_size = random_Int(0, 5);
		int random_place = random_Int(0, record_1.length - 1);
		int random_bitset_size = random_Int(0, 10);
		switch (random_Int(1, 8)) {
		case 1:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".test("+std::to_string(random_place) + ") == " + std::to_string(random_Bool()) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 2:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".test(" + std::to_string(random_place) + ") != " + std::to_string(random_Bool()) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 3:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() > " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 4:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() >= " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			break;
		case 5:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() < " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			
			break;
		case 6:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() <= " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}
			
			break;
		//case 7:
		//		op += "	for (int index = 0; index < " + std::to_string(for_loop_size) + "; index ++) {\n";
		//		op += random_bitset_op(number_of_index, records, 1);


		//		op += "	}\n";
		//	break;

		//case 8:
		//		op += "	int index_bitset_" + std::to_string(m) + "= 0;\n";
		//		op += "	while (index_bitset_" + std::to_string(m) + " < " + std::to_string(for_loop_size) + ") {\n";
		//		op += random_bitset_op(number_of_index, records, 1);
		//		op += "	index_bitset_" + std::to_string(m) + "++;\n";
		//		op += "	}\n";
		//	break;
		case 9:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() == " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}

			break;
		case 10:
			// multiple layer of if/else£ºinsert/replace element
			if (record_1.length > 0) {
				op += "	if (bitset_" + std::to_string(current) + ".size() != " + std::to_string(random_bitset_size) + ") {\n";
				auto temp_string_1 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_1;
				op += "	}\n";
				op += "	else {\n";
				auto temp_string_2 = random_bitset_op(number_of_index, records, random_Int(0, 5));
				op += temp_string_2;
				op += "	}\n";
			}

			break;
		}
		//std::cout << op << std::endl;
	}
	return op;
}


std::string create_bitset(int index) {
	std::string code;
	int bitset_elements_num = random_Int(5, 10);

	std::vector<bitset_records> bitset_records;

	int temp_bitset_value = 0;

	for (int n = 0; n < index; n++) {


		temp_bitset_value = create_bitset_int(bitset_elements_num);


		bitset_records.push_back({ bitset_elements_num });

		//print out secton

		code += "	std::bitset<" + std::to_string(bitset_elements_num) + "> bitset_" + std::to_string(n) + " (" + std::to_string(temp_bitset_value) + ");\n";

	}

	//random operations generated
	code += random_bitset_op(index, bitset_records);
	code += random_bitset_loop(index, bitset_records,1);

	//for (int m = 0; m < index; m++) {
	//	code += "	std::vector<" + stack_records[m].type + "> newstack_" + std::to_string(m) + "(stack_" + std::to_string(m) + ".begin(), stack_" + std::to_string(m) + ".end());\n";
	//	code += "	append_data(buffer, newstack_" + std::to_string(m) + ");\n";

	//}

	code += "\n";

	//for (const auto& record : deq_records) {
	//	std::cout << "Deque length: " << record.length
	//		<< ", Type: " << record.type << std::endl;
	//}


	code += "\n";
	return code;
}