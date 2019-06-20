#pragma once

#include <functional>
#include <algorithm>
using namespace std;

template <typename T, typename R=T>
class AVLTree {
	struct Node {
		T e;
		Node* l;
		Node* r;
		int h;
	Node(T e) : e(e), l(nullptr), r(nullptr), h(0) {}
	static int height(Node* n) {
		if (n == nullptr) {
			return -1;
		}
		else return n->h;
	}
	void updateH() {
		h = max(Node::height(l), Node::height(r)) +1;
	}
	};
	Node* root;
	int length;
	function<R(T)> key;

	void destroy(Node* n) {
		if (n != nullptr) {
			destroy(n->l);
			destroy(n->r);
			delete n;
		}
	}

	void rotAB(Node*& n) {
		Node* aux = n->l;
		n->l = aux->r;
		n->Node::updateH();
		aux->r = n;
		n = aux;
		n->Node::updateH();
	}

	void rotBA(Node*& n) {
		Node* aux = n->r;
		n->r = aux->l;
		n->updateH();
		aux->l = n;
		n = aux;
		n->updateH();
	}
	void balance(Node*& n) {
		int delta = Node::height(n->l) - Node::height(n->r);
		if (delta < -1) {
			if (Node::height(n->r->l) > Node::height(n->r->l)) {
				rotAB(n->r);
			}
			rotBA(n);
		}
		else {
			if (Node::height(n->l->r) > Node::height(n->l->l)) {
				rotBA(n->l);
			}
			rotAB(n);
		}
	}
	void Add(Node*& n , T e) {
		if (n == nullptr) {
			n = new Node(e);
			return;
		}
		else if (key(e) < key(n->e)) {
			Add(n->l, e);
		}
		else {
			Add(n->r, e);
		}
		balance(n);
		n->Node::updateH();
	}
public:
	AVLTree(function<R(T)> key = [](T a) { return a; }) : root(nullptr), length(0), key(key){

	}
	~AVLTree() {
		destroy(root);
	}
	int Height() {
		return Node::height(root);
	}
	int Size() {
		return length;
	}
	void add(T e) {
		Add(root, e);
		length++;
	}

};