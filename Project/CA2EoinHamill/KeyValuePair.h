#pragma once
//Setting up the class
template <typename K, typename V>
class KeyValuePair {
	K key;
	V value;

public:
	//Preparing Methods
	KeyValuePair();
	K& getKey();
	V& getValue();
	void setKey(K& keyIn);
	void setValue(V& valueIn);
	bool operator<(KeyValuePair<K, V>& other);
	bool operator>(KeyValuePair<K, V>& other);
	bool operator==(KeyValuePair<K, V>& other);

	

};
//Default Empty Constructor
template <typename K, typename V>
KeyValuePair<K,V>::KeyValuePair()
{
	this->key = K();
	this->value = V();
}

//Get key method
template <typename K, typename V>
K& KeyValuePair<K, V>::getKey()
{
	return this->key;
}

//Get value method
template <typename K, typename V>
V& KeyValuePair<K, V>::getValue()
{
	return value;
}

//Set Key
template <typename K, typename V>
void KeyValuePair<K, V>::setKey(K& keyIn)
{
	this->key = K(keyIn);
}

//Set Key
template <typename K, typename V>
void KeyValuePair<K, V>::setValue(V& valueIn)
{
	this->value = V(valueIn);
}

//Less then more then and == Operators
template <typename K, typename V>
bool KeyValuePair<K, V>::operator<(KeyValuePair<K, V> &other) {
	return this->getKey()<other.getKey();
}

template <typename K, typename V>
bool KeyValuePair<K, V>::operator>(KeyValuePair<K, V>& other) {
	return this->getKey() > other.getKey();
}

template <typename K, typename V>
bool KeyValuePair<K, V>::operator==(KeyValuePair<K, V>& other) {
	return this->getKey() == other.getKey();
}
