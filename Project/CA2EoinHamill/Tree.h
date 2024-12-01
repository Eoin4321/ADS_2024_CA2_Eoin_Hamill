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
	bool containsKey(K key);
	V& get(K key);
	//BinaryTree<K>keySet();
	void put(K key, V value);
	int size();
	bool removeKey(K key);
	V& operator[](K key);

	
};
//Stage 1

//Clear
template<class K, class V>
void Tree<K, V>::clear() {
	BinaryTree.clear();
}


//Add to the tree.
template<class K, class V>
void Tree<K, V>::put(K key, V value) {
	KeyValuePair<K, V> keyAndValue;
	keyAndValue.setKey(key);
	keyAndValue.setValue(value);

	BinaryTree.add(keyAndValue);
}

//get key
template<class K, class V>
V& Tree<K, V>::get(K key) {
	KeyValuePair<K, V> keyInput;;
	keyInput.setKey(key);

	try
	{
		return BinaryTree.get(keyInput).getValue();
	}
	catch (const std::exception&)
	{
		std::cout << "Key not found" << std::endl;
		KeyValuePair<K, V> emptyKeyValue;
		return emptyKeyValue.getValue();
	}
}

template<class K, class V>
int Tree<K, V>::size() {
	return this->BinaryTree.count();
}

//getter with key.
template<class K, class V>
V& Tree<K, V>::operator[](K key) {
	return this->get(key);
}

//Contains key
template<class K, class V>
bool Tree<K, V>::containsKey(K key) {
	KeyValuePair<K, V> keyInput;
	keyInput.setKey(key);
		try
	{
			BinaryTree.get(keyInput);
			return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}

//Remove a Key
template<class K,class V>
bool Tree<K, V>::removeKey(K key) {
	KeyValuePair<K, V> keyInput;
	keyInput.setKey(key);
	try
	{
		BinaryTree.remove(keyInput);
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}


