#pragma once
#include <iostream>
using namespace std;
template <class K,class V>
struct BSTreeNode {
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;

	K _key;
	V _val;
BSTreeNode(K key,V val) :
	_key(key),
	_val(val),
	_left(nullptr),
	_right(nullptr)
	{

	}
BSTreeNode(){}
};

template <class K, class V>
class BSTree {
	typedef BSTreeNode<K,V> Node;
private:
	Node* _root;
public:
	BSTree() :
		_root(nullptr){

	}
	bool Insert(const K& key, const V& value) {
		return _Insert(_root, key, value);
	}

	bool _Insert(Node*& root,const K& key, const V& value) {
		if (root == nullptr) {
			Node* tmp = new Node(key, value);
			root = tmp;
		}
		if (root->_key < key) {
			return _Insert(root->_right, key, value);
		}
		else if (root->_key > key) {
			return _Insert(root->_left, key, value);
		}
		else {
			return false;
		}
	}
	Node* Find(const K& key) {
		return _Find(_root,key);
	}
	Node* _Find(Node*& root, const K& key) {
		if (root == nullptr) {
			return nullptr;
		}
		if (root->_key == key) {
			return root;
		}
		if (root->_key < key) {
			return _Find(root->_right, key);
		}
		else if (root->_key > key) {
			return _Find(root->_left, key);
		}
		
		
	}
	bool Erase(const K& key) {
		return _Erase(_root, key);
	}
	bool _Erase(Node*& root, const K& key) {
		if (root == nullptr) {
			return false;
		}
		if (root->_key < key) {
			return _Erase(root->_right, key);
		}
		else if (root->_key > key) {
			return _Erase(root->_left, key);
		}
		else {
			Node* cur = root;
			if (cur->_left == nullptr) {
				Node* curR = cur->_right;
				delete cur;
				root = curR;
			}
			else if (cur->_right == nullptr) {
				Node* curL = cur->_left;
				delete cur;
				root = curL;
			}
			else {
				Node* tmp = cur->_left;
				Node* parent = nullptr;
				while (tmp->_right != nullptr) {
					parent = tmp;
					tmp = tmp->_left;
				}
				if (parent==nullptr) {
					tmp->_right = cur->_right;
				}
				else {
					parent->_right = nullptr;
					tmp->_left = cur->_left;
					tmp->_right = cur->_right;
				}
				delete cur;
				root = tmp;
				
			}
			return true;
		}
	}
	void _InOrder(Node* root) {
		if (root == nullptr) {
			return;
		}
		_InOrder(root->_left);
		cout << root->_key << ":" << root->_val << endl;
		_InOrder(root->_right);

	}
	void InOrder() {
		_InOrder(_root);
	}
};
