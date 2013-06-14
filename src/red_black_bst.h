/*
 * red_black_bst.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef RED_BLACK_BST_H_
#define RED_BLACK_BST_H_

#include <math.h>

const bool RED = true;
const bool BLACK = false;

template <class T, class S> struct Node{
	int size;
	bool color;
	T key;
	S value;
	Node<T, S> *left;
	Node<T, S> *right;

	Node(T t, S s, int i, bool b){
		size = i;
		color = b;
		key = t;
		value = s;
		left = nullptr;
		right = nullptr;
	};

	~Node(){

	};
};


template<class T, class S> class red_black_bst {
private:
	Node<T, S> *root;

	bool is_red(Node<T, S> *n);
	Node<T, S>* rotate_left(Node<T, S> *n);
	Node<T, S>* rotate_right(Node<T, S> *n);
	void flip_colors(Node<T, S> *n);

	int size(Node<T, S> *n);

	S get(Node<T, S>* n, T t);
	Node<T, S>* put(Node<T, S> *n, T t, S s);
public:
	red_black_bst();
	~red_black_bst();

	S get(T t);
	void put(T t, S s);
};

template<class T, class S> red_black_bst<T, S>::red_black_bst() {
	root = nullptr;

}

template<class T, class S> red_black_bst<T, S>::~red_black_bst() {

}

template<class T, class S> bool red_black_bst<T, S>::is_red(Node<T, S> *n) {
	if (n == nullptr)
		return false;
	return n->color == RED;
}

template<class T, class S> Node<T, S>* red_black_bst<T, S>::rotate_left(
		Node<T, S> *n) {
	Node<T, S> *tmp = n->right;
	n->right = tmp->left;
	tmp->left = n;
	tmp->color = n->color;
	n->color = RED;
	tmp->size = n->size;
	n->size = size(n->left) + size(n->right) + 1;
	return tmp;
}

template<class T, class S> Node<T, S>* red_black_bst<T, S>::rotate_right(
		Node<T, S> *n) {
	Node<T, S> *tmp = n->left;
	n->left = tmp->right;
	tmp->right = n;
	tmp->color = n->color;
	n->color = RED;
	tmp->size = n->size;
	n->size = size(n->left) + size(n->right) + 1;
	return tmp;
}

template<class T, class S> void red_black_bst<T, S>::flip_colors(
		Node<T, S> *n) {
	n->color = RED;
	n->left->color = BLACK;
	n->right->color = BLACK;
}

template<class T, class S> int red_black_bst<T, S>::size(Node<T, S>* n) {
	if (n == nullptr)
		return 0;
	else
		return n->size;
}

template<class T, class S> Node<T, S>* red_black_bst<T, S>::put(Node<T, S> *n,
		T t, S s) {
	if (n == nullptr)
		return new Node<T,S>(t, s, 1, RED);
	if (t < n->key)
		n->left = put(n->left, t, s);
	else if (t > n->key)
		n->right = put(n->right, t, s);
	else
		n->value = s;

	if (is_red(n->right) && !is_red(n->left))
		n = rotate_left(n);
	if (is_red(n->left) && is_red(n->left->left))
		n = rotate_right(n);
	if (is_red(n->left) && is_red(n->right))
		flip_colors(n);

	n->size = size(n->left) + size(n->right) + 1;
	return n;

}

template<class T, class S> void red_black_bst<T, S>::put(T t, S s) {
	root = put(root, t, s);
	root->color = BLACK;
}

template<class T, class S> S red_black_bst<T, S>::get(Node<T, S>* n, T t) {
	if (n == nullptr)
		return nullptr;
	if (t < n->key)
		return get(n->left, t);
	else if (t > n->key)
		return get(n->right, t);
	else
		return n->value;
}

template<class T, class S> S red_black_bst<T, S>::get(T t) {
	return get(root, t);
}


#endif /* RED_BLACK_BST_H_ */
