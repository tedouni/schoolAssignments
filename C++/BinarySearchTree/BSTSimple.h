#pragma once
#include "BSTNode.h"
#include <iostream>
using namespace std;

template<typename Key, typename Value> class BSTSimple;

template<typename Key, typename Value>
ostream& operator<<(ostream& os, BSTSimple<Key, Value> const& bst);

template<typename Key, typename Value>
class BSTSimple
{
public:
	BSTSimple();
	int size() const;
	Value get(Key key) const;
	void put(Key key, Value value);

	friend ostream& operator<< <Key, Value> (ostream& os, BSTSimple<Key, Value> const& bst);

	void print(ostream& os, typename BSTNode<Key, Value>::TRAVERSAL order) const;

private:
	int size(BSTNode<Key, Value> const* node) const;
	Value get(BSTNode<Key, Value> const& node, Key key) const;
	BSTNode<Key, Value> *
    put(BSTNode<Key, Value>* node, Key key, Value value);
private:
	BSTNode<Key, Value>* _root;

};

template<typename Key, typename Value>
BSTSimple<Key, Value>::BSTSimple() :_root(NULL) {}

template<typename Key, typename Value>
Value BSTSimple<Key, Value>::get(Key key) const { return get(_root, key); }

template<typename Key, typename Value>
int BSTSimple <Key, Value>::size() const { return _root->_size; }

template<typename Key, typename Value>
void BSTSimple<Key, Value>::put(Key key, Value value)
{
	_root = put(_root, key, value);
}

template <typename Key, typename Value>
BSTNode<Key,Value>*
BSTSimple<Key,Value>::put(BSTNode <Key, Value>* node, Key key, Value value)
{
    if (node ==NULL)
    {
        return new BSTNode<Key, Value> (key,value,1);
    }
    
    if (key<node->key())
    {
        node->left() = put(node->left(), key, value);
        
    }
    else if (key>node->key())
    {
        node->right() = put(node->right(),key,value);
        
    }
    
    else
    {
        node->value() = value;
    }
    
    node->size() =size(node->left()) +size(node->right()) + 1;
    return node;
}

template<typename Key, typename Value>
int BSTSimple<Key, Value>::size(BSTNode<Key, Value> const* node) const
{
	return (node == NULL) ? 0 : node->size();
}

template<typename Key, typename Value>
Value BSTSimple<Key, Value>::get(BSTNode<Key, Value> const& node, Key key) const
{
	if (node == NULL)
		return NULL;
	if (key < node->key())
	{
		return get(node.left(), key);
	}
	else if (key> node->key())
	{
		return get(node.right(),key);
	}

	else
	{
		return node.value();
	}

	
}


template<typename Key, typename Value>
void BSTSimple<Key, Value> ::print(ostream& os, typename BSTNode<Key, Value>::TRAVERSAL order) const
{
	::print(os, _root, order);
}

template<typename Key, typename Value>
ostream& operator<<(ostream& os, BSTSimple<Key, Value> const& bst)
{
	os << "BST[";
	print(os, bst._root, BSTNode<Key, Value>::INORDER);
	return os << "]";
}

