/*
 * binary_search_vector.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef BINARY_SEARCH_VECTOR_H_
#define BINARY_SEARCH_VECTOR_H_

#include <vector>
#include <iterator>
#include <iostream>

template<class T, class S> class binary_search_vector {
private:
	int size;
	std::vector<T> keys;
	std::vector<S> values;
	int rank(T t);
public:
	binary_search_vector();
	~binary_search_vector();

	void put(T t, S s);
	S get(T t);

	void remove(T t);

	int get_size() const;
	void print();
};

template<class T, class S> binary_search_vector<T, S>::binary_search_vector() {
	size = 0;
}
;

template<class T, class S> void binary_search_vector<T, S>::put(T t, S s) {
	int i = rank(t);
	if (i < size && keys[i] == t) {
		values[i] = s;
		return;
	} else {
// 		std::vector<T>::iterator it;
// 		std::vector<S>::iterator is;

		auto it = keys.begin() + i;
		auto is = values.begin() + i;

		keys.insert(it, t);
		values.insert(is, s);
		size++;

	}

}

template<class T, class S> S binary_search_vector<T, S>::get(T t) {
	for (int i = 0; i < size; ++i)
		if (keys[i] == t)
			return values[i];
}

template<class T, class S> int binary_search_vector<T, S>::rank(T t) {
	int lo = 0;
	int hi = keys.size() - 1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (t < keys[mid])
			hi = mid - 1;
		else if (t > keys[mid])
			lo = mid + 1;
		else
			return mid;
	}
	return lo;
}
;

template<class T, class S> int binary_search_vector<T, S>::get_size() const {
	return size;
}

template<class T, class S> binary_search_vector<T, S>::~binary_search_vector() {

}

template<class T, class S> void binary_search_vector<T, S>::remove(T t) {
	int i = rank(t);
	if (i < size && keys[i] == t){
		auto it = keys.begin() + i;
		auto is = values.begin() + i;
		keys.erase(it);
		values.erase(is);
		size--;
	}

}

template<class T, class S> void binary_search_vector<T, S>::print() {
	for (int i = 0; i < size; ++i) {
		std::cout << keys[i] << '\t' << values[i] << '\n';
	}
}


#endif /* BINARY_SEARCH_VECTOR_H_ */
