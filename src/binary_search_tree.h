/*
 * binary_search_tree.h
 *
 *  Created on: 14-06-2013
 *      Author: lukasz
 */

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include <math.h>

template <class T, class S> struct Node{
  T key;
  S value;
  int size;
  Node *left;
  Node *right;

  Node (T t, S s, int n){
    key = t;
    value = s;
    size = n;
    left = nullptr;
    right = nullptr;
  }

  Node(const Node<T,S> *n){
	  key = n->key;
	  value = n->value;
	  size = n->size;
	  left = nullptr;
	  right = nullptr;
  };
  ~Node(){

  };
};

template<class T, class S> class bst {
private:
	Node<T, S> *root;

	S get(Node<T, S>* n, T t);
	Node<T, S>* put(Node<T, S>* n, T t, S s);
	Node<T,S>* remove(Node<T,S> *n, T t);

	Node<T,S>* remove_min(Node<T,S>* n);

	int size(Node<T, S> *n);
	int height(Node<T, S> *n);
	Node<T,S>* min(Node<T,S> *n);

	Node<T,S>* find_min(Node<T,S> *n);


public:
	bst();
	~bst();

	S get(T t);
	void put(T t, S s);
	void remove(T t);

//	void remove_min();

	int size();
	int height();
	T min();
};

template<class T, class S> bst<T, S>::bst() {
	root = nullptr;
}

template<class T, class S> bst<T, S>::~bst() {

}

template<class T, class S> S bst<T, S>::get(T t) {
	return get(root, t);
}

template<class T, class S> S bst<T, S>::get(Node<T, S>* n, T t) {
	if (n == nullptr)
		return nullptr;
	if (t < n->key)
		return get(n->left, t);
	else if (t > n->key)
		return get(n->right, t);
	else
		return n->value;
}


template<class T, class S> void bst<T, S>::put(T t, S s) {
	root = put(root, t, s);
}

template<class T, class S> Node<T, S>* bst<T, S>::put(Node<T, S>* n, T t, S s) {
	if (n == nullptr) {
// 		size++;
		return new Node<T, S>(t, s, 1);
	}
	if (t < n->key)
		n->left = put(n->left, t, s);
	else if (t > n->key)
		n->right = put(n->right, t, s);
	else
		n->value = s;
	n->size = size(n->left) + size(n->right) + 1;
	return n;
}





template<class T, class S> int bst<T, S>::height() {
	return height(root);
}
template<class T, class S> int bst<T, S>::height(Node<T, S>* n) {
	if (n == nullptr)
		return -1;
	return 1 + fmax(height(n->left), height(n->right));
}


template<class T, class S> int bst<T, S>::size() {
	return size(root);
}

template<class T, class S> int bst<T, S>::size(Node<T, S>* n) {
	if (n == nullptr)
		return 0;
	else
		return n->size;
}


template<class T, class S> T bst<T, S>::min() {
	return min(root)->key;
}
template<class T, class S> Node<T, S>* bst<T, S>::min(Node<T,S> *n) {
	if (n->left == nullptr) return n;
	return (min(n->left));
}

template<class T, class S> Node<T, S>* bst<T, S>::remove(Node<T, S> *n,T t) {
	if (n == nullptr) return nullptr;
	if (t < n->key) n->left = remove(n->left, t);
	else if (t > n->key) n->right = remove(n->right, t);
	else{
		if (n->right == nullptr) return n->left;
		if (n->left == nullptr) return n->right;
		Node<T,S> *t = n;
//		n = min(t->right);
		Node<T,S> * x = new Node<T,S>(min(t->right));
		n = x;
		n -> right = remove_min(t->right);
		n -> left = t -> left;
		delete t;
	}
	n->size = size(n->left) + size(n->right) + 1;
	return n;
}

template<class T, class S> void bst<T, S>::remove(T t) {
	root = remove(root, t);
}

template<class T, class S> Node<T, S>* bst<T, S>::remove_min(Node<T, S>* n) {
	if (n->left == nullptr){
		Node<T,S> *t = n;
		Node<T,S> *x = n->right;
		delete t;
		return x;
	}
	n->left = remove_min(n->left);
	n->size = size(n->left) + size(n->right) + 1;
	return n;
}

template<class T, class S> Node<T, S>* bst<T, S>::find_min(Node<T, S>* n) {

}


#endif /* BINARY_SEARCH_TREE_H_ */
