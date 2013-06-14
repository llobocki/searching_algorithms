/*
 * binary_search.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <vector>

template <class T> int rank (const std::vector<T> a, T key )
{
	int lo = 0;
	int hi = a.size() -1;
	while ( lo <= hi ) {
		int mid = lo + ( hi - lo ) / 2;
		if ( key < a[mid] ) hi = mid - 1;
		else if ( key > a[mid] ) lo = mid + 1;
		else return mid;
	}
	return -1;
}





#endif /* BINARY_SEARCH_H_ */
