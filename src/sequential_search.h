/*
 * sequential_search.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef SEQUENTIAL_SEARCH_H_
#define SEQUENTIAL_SEARCH_H_

#include <iostream>

template <class T, class S> struct Node {
	T key;
	S value;
	class Node<T , S> *next;
	Node() {
		next = 0;
	}
	Node ( T k, S v, Node *p = 0 ) {
		key = k;
		value = v;
		next = p;
	}
	~Node(){

	};
};

template <class T, class S> class sequential_search {
private:
	int size;
	Node<T , S > *root;
public:
	sequential_search();
	~sequential_search();

	S get ( T k );

	void put ( T k, S v );

	void remove (T t);

	int get_size();
};

template <class T, class S> sequential_search<T, S>::sequential_search()
{
	root = nullptr;
	size = 0;
}

template <class T, class S>  S sequential_search<T, S>::get ( T k )
{
	Node< T, S > *x = root;
	for ( int i = 0; i < size; ++i ) {
		if ( x->key == k )
			return x->value;
		else
			x = x->next;
	}
//	return nullptr;
}


template <class T, class S> void sequential_search<T, S>::put ( T k, S v )
{
	Node< T, S > *x = root;
	for ( int i = 0; i < size; ++i ) {
		if ( x->key == k ) {
			x->value = v;
			return;
		} else
			x = x->next;
	}
	root = new Node<T, S> ( k, v, root );
	size++;

}

template <class T, class S> void sequential_search<T,S>::remove(T t){
	if ( size > 0 ) {
		if ( size ==1 && t == root->key ) {
			delete root;
			root = nullptr;
		}
		else if(t == root->key){
			Node<T ,S> *tmp = root;
			root = root->next;
			delete tmp;
			tmp = nullptr;
			size--;
		}
		else {
			Node<T, S> *prev;
			Node<T, S> *tmp;
			for ( prev = root, tmp = root->next; tmp != 0 && ! ( tmp->key ==t ); prev = prev->next, tmp = tmp ->next );
			if ( tmp != 0 ) {
				prev->next = tmp-> next;
				delete tmp;
				tmp = nullptr;
				size--;
			}
		}
	}
}

template<class T, class S> sequential_search<T, S>::~sequential_search() {
	Node<T,S> *tmp;
	int i = size;
	while((i--) > 0){
		tmp = root->next;
		delete root;
		root = tmp;
	}
}

template<class T, class S> int sequential_search<T, S>::get_size() {
	return size;
}



#endif /* SEQUENTIAL_SEARCH_H_ */
