#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


template<typename T, typename R = T>
class AVLTree {
	struct Node {
		T e;
		Node* R;
		Node* L;
		int altura;

		Node(T e) : e(e), R(nullptr), L(nullptr), altura(0) {}
		static int height(Node* a) {
			if (a == nullptr) {
				return -1;
			}
			else return a->altura;
		}
		void updateH() {
			this->altura = max(Node::height(L), Node::height(R)) + 1;
		}

	};

	Node* root;
	int l;
	function<R(T)> key;
	char tipo;
	void inOrder(Node* a, vector<T>*& f) {
		if (a != nullptr) {
			cout << "memori" << endl;
			inOrder(a->L,f);
		
			(*f).push_back(a->e);
			inOrder(a->R,f);
		}
	}
	void destroy(Node*& a) {
		if (a != nullptr) {
			destroy(a->L);
			destroy(a->R);
			delete a;
		}
	}
	void RotAB(Node*& a) {
		Node* aux = a->L;
		a->L = aux->R;
		a->updateH();
		aux->R = a;
		a = aux;
		a->updateH();
	}
	void RotBA(Node*& a) {
		Node* aux = a->R;
		a->R = aux->L;
		a->updateH();
		aux->L = a;
		a = aux;
		a->updateH();
	}
	void Balance(Node*& a) {
		int delta = Node::height(a->L) - Node::height(a->R);
		if (delta < -1) {
			if (Node::height(a->R->L) > Node::height(a->R->R)) {
				RotAB(a->R);
			}
			RotBA(a);
		}
		else if (delta > 1) {
			if (Node::height(a->L->R) > Node::height(a->L->L)) {
				RotBA(a->L);
			}
			RotAB(a);
		}
	}
	
	void add(T e, Node*& a) {
		if (tipo == 'n') {
			if (a == nullptr) {
				a = new Node(e);
				return;
			}
			else if (key(e) < key(a->e)) {
				add(e, a->L);
			}
			else {
				add(e, a->R);
			}
		}
		else {
			if (a == nullptr) {
				a = new Node(e);
				return;
			}
			else if (key(e).compare(key(a->e)) == 1) {
				add(e, a->L);
			}
			else {
				add(e, a->R);
			}
		}
		Balance(a);
		a->updateH();
	}
	bool buscar(Node* a, T b, vector<T*>&* w) {
		vector<>
		if (a == nullptr) {
			return false;
		}
		else if (key(a->e) == key(b->e)) {
			
		}
		else if (buscar(a->L, b)) {
			return true;
		}
		else if (buscar(a->R, b)) {
			return true;
		}
		else return false;

	}
public:

	AVLTree(function<R(T)> key = [](T a) { return a; }) : key(key), l(0), root(nullptr) {

	}
	~AVLTree() {
		destroy(root);
	}

	vector<T>* Ordenar() {
		vector<T>* f = new vector<T>;
		inOrder(root, f);
		return f;
	}
	void Add(T e) {
		add(e, root);
		l++;
	}
	int size() {
		return l;
	}
	int height() {
		return Node::height(root);
	}
	void setTipo(string num) {
		if ((num[0] >= 65 && num[0] <= 90) || (num[0] >= 97 && num[0] <= 122)) {
			tipo = 's';
		}
		else {
			tipo = 'n';
		}
	}
	void Buscar(T a) {
		if (buscar(root, a)) cout << "Se encontro el elemento" << endl;
		else cout << "No se encontro el elemento" << endl;
	}
};