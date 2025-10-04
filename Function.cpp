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
#include <variant>

int randomInt(int min, int max) {
	return min + rand() % (max - min + 1);
}

int random_Int(int min, int max) {
	if (max <= 0)
		return 0;
	else
		return min + rand() % (max - min + 1);
}
unsigned int random_UInt(unsigned int min, unsigned int max) {
	return min + rand() % (max - min + 1);
}
short random_Short(short min, short max) {
	return min + rand() % (max - min + 1);
}

// unsigned short
unsigned short random_UShort(unsigned short min, unsigned short max) {
	return min + rand() % (max - min + 1);
}

// long
long random_Long(long min, long max) {
	return min + rand() % (max - min + 1);
}

// unsigned long
unsigned long random_ULong(unsigned long min, unsigned long max) {
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
unsigned char random_UChar() {
	const unsigned char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int generated_char = rand() % (sizeof(charset) - 1); // Exclude null terminator
	return charset[generated_char];
}
// Function to generate a random boolean value
bool random_Bool() {
	return rand() % 2; // Returns either 0 (false) or 1 (true)
}

std::pair<aval_Type, std::string> random_type() {
	std::string type;
	aval_Type data_type;
	switch (random_Int(1, 11)) {
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
		type = "unsigned char";
		data_type = UCHAR;
		break;
	case 7:
		type = "short";
		data_type = SHORT;
		break;
	case 8:
		type = "unsigned short";
		data_type = USHORT;
		break;
	case 9:
		type = "unsigned int";
		data_type = UINT;
		break;
	case 10:
		type = "long";
		data_type = LONG;
		break;
	case 11:
		type = "unsigned long";
		data_type = ULONG;
		break;
		//case 6:
		//	type = "std::vector<int>";
		//	data_type = INT_2D;
		//	break;
		//case 7:
		//	type = "std::vector<float>";
		//	data_type = FLOAT_2D;
		//	break;
		//case 8:
		//	type = "std::vector<double>";
		//	data_type = DOUBLE_2D;
		//	break;
		//case 9:
		//	type = "std::vector<char>";
		//	data_type = CHAR_2D;
		//	break;
		//case 10:
		//	type = "std::vector<bool>";
		//	data_type = BOOL_2D;
		//	break;
	}
	return { data_type,type };
}
std::vector<int> create_vec_int(int length = 1) {
	std::vector<int> temp;
	for (int n = 1; n <= length; n++) {
		//switch (random_Int(1, 2)) {
		//case 1:
		temp.push_back(random_Int(-100, 100));
		//break;

	//case 2:
	//	temp.push_back(random_Bool());
	//	break;
	//}
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

std::vector<unsigned int> create_vec_uint(int length = 1) {
	std::vector<unsigned int> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UInt(0, 100));
	}
	return temp;
}

std::vector<short> create_vec_short(int length = 1) {
	std::vector<short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Short(-100, 100));
	}

	return temp;
}

std::vector<unsigned short> create_vec_ushort(int length = 1) {
	std::vector<unsigned short> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UShort(0, 100));
	}

	return temp;
}

std::vector<unsigned char> create_vec_uchar(int length = 1) {
	std::vector<unsigned char> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_UChar());
	}

	return temp;
}

std::vector<long> create_vec_long(int length = 1) {
	std::vector<long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_Long(-100, 100));
	}

	return temp;
}

std::vector<unsigned long> create_vec_ulong(int length = 1) {
	std::vector<unsigned long> temp;
	for (int n = 1; n <= length; n++) {
		temp.push_back(random_ULong(0, 100));
	}

	return temp;
}

