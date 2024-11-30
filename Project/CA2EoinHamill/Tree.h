#pragma once
#include "BinaryTree.h"
#include "BSTNode.h"
#include "KeyValuePair.h"
using namespace std;

template<class K, class V>
class Tree
{
public:
	BinaryTree<KeyValuePair<K, V>> BinaryTree;
	
	Tree() {

	}
	
	//Stage 1 methods
	void clear();
	//bool containsKey(K key);
	//V& get(K key);
	//BinaryTree<K>keySet();
	void put(K key, V value);
	//int size();
	//Bool removeKey(K key);
	//V& operator[K key];

	
};
//Add to the tree.
template<class K, class V>
void Tree<K, V>::put(K key, V value) {
	KeyValuePair<K, V> keyAndValue;
	keyAndValue.setKey(key);
	keyAndValue.setValue(value);

	BinaryTree.add(keyAndValue);
}
//Stage 1 Clear
template<class K, class V>
void Tree<K, V>::clear() {
	BinaryTree.clear();
}


