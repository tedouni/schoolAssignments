#pragma once

#include <iostream>
using namespace std;
template <typename Key, typename Value> class BSTNode;

template <typename Key, typename Value>
void print(ostream& os, BSTNode<Key, Value> *node, typename BSTNode<Key, Value>::TRAVERSAL order);

template <typename Key, typename Value>
ostream& operator<<(ostream& os, BSTNode<Key, Value> *node);

template <typename Key, typename Value>
class BSTNode
{
public:
	BSTNode(Key key, Value value, int size, BSTNode<Key, Value> *left = NULL, BSTNode<Key, Value> *right = NULL);
	int size() const;
	int& size();

	Value value() const;
	Value& value();

	Key key() const;
    
	BSTNode<Key, Value>* left() const;
	BSTNode<Key, Value>* &left();

	BSTNode<Key, Value>* right() const;
	BSTNode<Key, Value>*& right();

	bool operator <(BSTNode<Key, Value> const& other) { return _key < other._key; }
	bool operator >(BSTNode<Key, Value> const& other) { return _key>other._key; }
	bool operator >=(BSTNode<Key, Value> const& other) { return _key >= other._key;}
	bool operator <=(BSTNode<Key, Value> const& other) { return _key <= other._key; }
	bool operator == (BSTNode<Key, Value> const& other) { return _key == other._key; }

	enum TRAVERSAL { PREORDER, INORDER, POSTORDER, LEVELORDER};

	friend void print<Key, Value>(ostream& os, BSTNode<Key, Value> *node, TRAVERSAL order);
	friend ostream& operator << <Key, Value> (ostream& os, BSTNode<Key, Value> *node);

private:
	Key _key;
	Value _value;
	int _size;
	BSTNode<Key, Value> *_left, *_right;

};

template <typename Key, typename Value>
BSTNode<Key, Value> ::BSTNode(Key key, Value value, int size, BSTNode<Key, Value> * left, BSTNode<Key, Value> *right)
:_key(key), _value(value), _size(size), _left(left), _right(right) { }

template <typename Key, typename Value>
int BSTNode<Key, Value> ::size() const { return _size; }

template <typename Key, typename Value>
int& BSTNode<Key, Value> ::size() { return _size; }

template <typename Key, typename Value>
Value BSTNode<Key, Value>::value() const { return _value; }

template <typename Key, typename Value>
Value& BSTNode<Key, Value> ::value() { return _value; }

template <typename Key, typename Value>
BSTNode<Key, Value> *BSTNode<Key, Value> ::left() const { return _left; }

template <typename Key, typename Value>
BSTNode<Key, Value> *& BSTNode<Key, Value> ::left()  { return _left; }

template <typename Key, typename Value>
BSTNode<Key, Value> *BSTNode<Key, Value> ::right() const { return _right; }

template <typename Key, typename Value>
BSTNode<Key, Value> *& BSTNode<Key, Value> ::right()  { return _right; }

template <typename Key, typename Value> Key
BSTNode<Key,Value>::key() const {return _key;}

template <typename Key, typename Value>
void print(ostream& os, BSTNode<Key, Value> *node, typename BSTNode<Key, Value>::TRAVERSAL order)
{
	if (node == NULL )
		return;

	switch (order)
	{
	case BSTNode<Key, Value> ::TRAVERSAL::PREORDER: 
		os << node << endl;
		print(os, node->_left, order);
		print(os, node->_right, order);
		break;

	case BSTNode<Key,Value>::TRAVERSAL::INORDER:
		print(os, node->_left, order);
		os << node << endl;
		print(os, node->_right, order);
		break;

	case BSTNode<Key,Value>::TRAVERSAL::POSTORDER:
		print(os, node->_left, order);
		print(os, node->_right, order);
		os << node << endl;
		break;
		
	default:
		throw invalid_argument("traversal order incorrect");
		break;
	}
}

template <typename Key, typename Value>
ostream& operator<<(ostream& os, BSTNode<Key, Value>* node)
{
	os << "BSTNode<";
	os << "Key=" << node->_key << ",value=" << node->_value;
	return os << ",size=" << node->_size << "]";
}