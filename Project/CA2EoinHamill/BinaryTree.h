#pragma once
#include "BSTNode.h"

#include <vector>
template <class T>
class BinaryTree
{
	//Helper method
	void addItemToArray(BSTNode<T>* node, int &pos, T *arr);
public:
	//Pointer to root
	BSTNode<T> *root;
	//Default Constructor
	BinaryTree();
	//Constructor to copy another tree
	BinaryTree(const BinaryTree<T> &other);
	BinaryTree<T> operator=(const BinaryTree<T>& other);
	//Adding to a tree
	void add(T& item);
	//Remove from the tree
	bool remove(T& item);
	//Stage 1 methods
	void clear();
	/*bool containsKey(K key);
	V& get(K key);
	BinaryTree<K>keySet();*/
	//void put(K key, V value);
	/*int size();
	Bool removeKey(K key);
	V& operator[K key];*/




	//counts all the BSTnodes in the tree
	int count();
	//Gets a item from the binary tree
	T& get(T& item);
	//Prints
	void printInOrder();
	void printInOrder(BSTNode<T> *node);
	void printPreOrder();
	void printPreOrder(BSTNode<T> *node);
	void printPostOrder();
	void printPostOrder(BSTNode<T> *node);
	//To array
	T* toArray();
	//Destructor
	~BinaryTree();
};

//Constructors
template <class T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}


template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other)
{
	root = nullptr;
	if(other.root != nullptr)
		root = new BSTNode<T>(*other.root);
}

//Adds all nodes from a different tree into this one
template <class T>
BinaryTree<T> BinaryTree<T>::operator=(const BinaryTree<T>& other)
{
	if (this == &other)
		return *this;
	if (other.root != nullptr)
		root = new BSTNode<T>(*other.root);
	else
		root = nullptr;
	return *this;

}

//Add
template <class T>
void BinaryTree<T>::add(T& item)
{
	if (root == nullptr)
	{
		root = new BSTNode<T>(item);
		root->setItem(item);
	}
	else
	{
		root->add(item);
	}
}
//Counts all the nodes in the tree
template <class T>
int BinaryTree<T>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}
//remove
template <class T>
bool BinaryTree<T>::remove(T& item)
{
	BSTNode<T> *toBeRemoved = root;
	BSTNode<T> *parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getItem() == item)
		{

			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item)
			{
				toBeRemoved = toBeRemoved->getLeft();
			}
			else
			{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T> *newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}

	BSTNode<T> *smallestParent = toBeRemoved;
	BSTNode<T> *smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}

}
//Get
template <class T>
T& BinaryTree<T>::get(T& item)
{
	bool found = false;
	BSTNode<T>* current = root;
	while (!found)
	{
	
		if (current == nullptr)
			break;
		if (current->getItem() == item)
			return current->getItem();
		else if (current->getItem() > item)
			current = current->getLeft();
		else
			current = current->getRight();
	}
	throw logic_error("ITem not found");
}
//Adding to an array
template <class T>
void BinaryTree<T>::addItemToArray(BSTNode<T>* node, int &pos, T *arr)
{
	if (node != nullptr)
	{
		addItemToArray(node->getLeft(), pos, arr);
		arr[pos] = node->getItem();
		pos++;
		addItemToArray(node->getRight(), pos, arr);
	}

}
//Change to an array
template <class T>
T* BinaryTree<T>::toArray()
{
	T *arr = new T[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}

template <class T>
//Clear method
void BinaryTree<T>::clear()
{
	delete root;
	root = nullptr;
}
//Destructor
template <class T>
BinaryTree<T>::~BinaryTree()
{
	if (root != nullptr)
	{
		delete root;
		root = nullptr;
	}
}

//Prints
template<class T>
void BinaryTree<T>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}
template<class T>
void BinaryTree<T>::printInOrder(BSTNode<T> *node)
{
	if (node == nullptr)
		return;

	printInOrder(node->getLeft());
	cout << node->getItem() << "";
	printInOrder(node->getRight());
}

template<class T>
void BinaryTree<T>::printPreOrder()
{
	this->printPreOrder(root);
	cout << endl;
}
template<class T>
void BinaryTree<T>::printPreOrder(BSTNode<T> *node)
{
	if (node == nullptr)
		return;

	cout << node->getItem() << "";
	printPreOrder(node->getLeft());
	printPreOrder(node->getRight());
	
}

template<class T>
void BinaryTree<T>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}
template<class T>
void BinaryTree<T>::printPostOrder(BSTNode<T> *node)
{
	if (node == nullptr)
	{
		return;
	}
	printPostOrder(node->getLeft());
	printPostOrder(node->getRight());
	cout << node->getItem() << "";
}

