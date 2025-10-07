#ifndef random_stl_program_H
#define random_stl_program_H
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <initializer_list>
#include <list>
#include <array>
#include <string>
#include <unordered_set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include<functional>
#include <fstream>
#include <climits>

#ifdef JASPER_C
#include <jasperc.h>
#endif

uint32_t simple_hash(const void* data, size_t len) {
	const uint8_t* bytes = static_cast<const uint8_t*>(data);
	uint32_t hash = 2166136261u; // FNV offset basis
	for (size_t i = 0; i < len; ++i) {
		hash ^= bytes[i];
		hash *= 16777619u; // FNV prime
	}
	return hash;
}

template <typename T>
void append_data(std::vector<uint8_t>& buffer, const std::vector<T>& vec) {
	const uint8_t* raw = reinterpret_cast<const uint8_t*>(vec.data());
	buffer.insert(buffer.end(), raw, raw + vec.size() * sizeof(T));
}

void append_data(std::vector<uint8_t>& buffer, const std::vector<bool>& vec) {
	for (bool b : vec) {
		buffer.push_back(b ? 1 : 0);
	}
}

template <typename T>
void append_data(std::vector<uint8_t>& buffer, const T& value) {
	const uint8_t* raw = reinterpret_cast<const uint8_t*>(&value);
	buffer.insert(buffer.end(), raw, raw + sizeof(T));
}
inline void append_data(std::vector<uint8_t>& buffer, bool value) {
	buffer.push_back(value ? 1 : 0);
}

template<typename K, typename V>
std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::map<K, V>& m) {
	std::vector<K> keys;
	std::vector<V> values;
	keys.reserve(m.size());
	values.reserve(m.size());
	for (const auto& p : m) {
		keys.push_back(p.first);
		values.push_back(p.second);
	}
	return { keys, values };
}
template<typename K, typename V>
std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::unordered_map<K, V>& m) {
	std::vector<K> keys;
	std::vector<V> values;
	keys.reserve(m.size());
	values.reserve(m.size());
	for (const auto& p : m) {
		keys.push_back(p.first);
		values.push_back(p.second);
	}
	return { keys, values };
}
template<typename K, typename V>
std::pair<std::vector<K>, std::vector<V>> map_to_vectors(const std::multimap<K, V>& m) {
	std::vector<K> keys;
	std::vector<V> values;
	keys.reserve(m.size());
	values.reserve(m.size());
	for (const auto& p : m) {
		keys.push_back(p.first);
		values.push_back(p.second);
	}
	return { keys, values };
}

#endif