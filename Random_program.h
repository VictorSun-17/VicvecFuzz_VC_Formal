#include <list>
#include <stack>
#include <string>
#include <vector>
#ifndef Random_program_H
#define Random_program_H

int randomInt(int min, int max);
int random_Int(int min, int max);
unsigned int random_UInt(unsigned int min, unsigned int max);
short random_Short(short min, short max);
unsigned short random_UShort(unsigned short min, unsigned short max);
long random_Long(long min, long max);
unsigned long random_ULong(unsigned long min, unsigned long max);
float random_Float(float min, float max);
double random_Double(double min, double max);
char random_Char();
unsigned char random_UChar();
bool random_Bool();

enum aval_Type {
	INT,
	UINT,
	DOUBLE,
	CHAR,
	UCHAR,
	BOOL,
	FLOAT,
	SHORT,
	USHORT,
	LONG,
	ULONG,

	INT_2D,
	DOUBLE_2D,
	CHAR_2D,
	BOOL_2D,
	FLOAT_2D,
	NONE
};

struct vector_records {
	int length;
	std::string type;
};
struct array_records {
	int length;
	std::string type;
};
struct deque_records {
	int length;
	std::string type;
};
struct queue_records {
	int length;
	std::string type;
};
struct set_records {
	int length;
	std::string type;
};
struct list_records {
	int length;
	std::string type;
};
struct map_records {
	int length;
	std::string type_1;
	std::string type_2;
};
struct multimap_records {
	int length;
	std::string type_1;
	std::string type_2;
};
struct stack_records {
	int length;
	std::string type;
};


struct container_record {
	int vec_length;
	std::string vec_type;
	int ary_length;
	std::string ary_type;
	int que_length;
	std::string que_type;
	int deq_length;
	std::string deq_type;
	int set_length;
	std::string set_type;
	int list_length;
	std::string list_type;
	int map_length;
	std::string map_type_1;
	std::string map_type_2;
	int multimap_length;
	std::string multimap_type_1;
	std::string multimap_type_2;
	int stack_length;
	std::string stack_type;
	//int bitset_length;

};



std::vector<int> create_vec_int(int length);
std::vector<float> create_vec_float(int length);
std::vector<char> create_vec_char(int length);
std::vector<double> create_vec_double(int length);
std::vector<bool> create_vec_bool(int length);
std::vector<unsigned int> create_vec_uint(int length);
std::vector<short> create_vec_short(int length);
std::vector<unsigned short> create_vec_ushort(int length);
std::vector<unsigned char> create_vec_uchar(int length);
std::vector<long> create_vec_long(int length);
std::vector<unsigned long> create_vec_ulong(int length);
std::pair<aval_Type, std::string> random_type();

std::tuple<std::string, std::string, std::vector<array_records>>  create_array(int index);
std::string create_bitset(int index);
std::tuple<std::string, std::string, std::vector<deque_records>> create_deque(int index);
std::tuple<std::string, std::string, std::vector<list_records>> create_list(int index);
std::tuple<std::string, std::string, std::vector<map_records>>  create_map(int index);
std::tuple<std::string, std::string, std::vector<multimap_records>> create_multimap(int index);
std::tuple<std::string, std::string, std::vector<queue_records>> create_queue(int index);
std::tuple<std::string, std::string, std::vector<set_records>> create_set(int index);
std::tuple<std::string, std::string, std::vector<stack_records>> create_stack(int index);
std::string create_unoredered_map(int index);
std::string create_unordered_set(int index);
std::tuple<std::string, std::string, std::vector<vector_records>> create_vec(int index);

template<typename K>
std::string vector_to_string(std::vector<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		oss += std::to_string(temp_vector[i - 1]);
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}

template<typename K>
std::string deque_to_string(std::deque<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		oss += std::to_string(temp_vector[i - 1]);
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}

template<typename K>
std::string queue_to_string(std::queue<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		oss += std::to_string(temp_vector.front());
		temp_vector.pop();
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}
template<typename K>
std::string set_to_string(std::set<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		auto it = temp_vector.begin();
		advance(it, i - 1);
		auto value = *it;
		oss += std::to_string(value);
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}
template<typename K>
std::string list_to_string(std::list<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		auto it = temp_vector.begin();
		advance(it, i - 1);
		auto value = *it;
		oss += std::to_string(value);
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}

template<typename K>
std::string stack_to_string(std::stack<K> temp_vector) {
	std::string oss;
	int elements_num = temp_vector.size();
	for (int i = 1; i <= elements_num; i++) {
		oss += std::to_string(temp_vector.top());
		temp_vector.pop();
		if (i != elements_num) {
			oss += ", "; // Add a separator between numbers
		}
	}
	return oss;
}

//template<typename K>
//std::vector<container_record> append_record(std::vector<container_record> container_record, std::vector<K> record) {
//
//
//
//	return 
//}

#endif