#pragma once

#include <vector>
#include <string>
#include "Nodos.h"

using namespace std;

class Row {
public:
	Row() {

	}
	
private:
	
	int tipo;
	int size = 0;
	vector<Node*> datos;
	

class iterator {
	unsigned int pos;
	vector<Node*> f;
	public:
	
		iterator(vector<Node*> f, unsigned int pos) : f(f),pos(pos) {}
		iterator(vector<Node*> f) :  pos(0) {}
		bool operator != (iterator other) {
			return this->pos != other.pos;
		}
		string operator *() {
			return f[pos]->getElem();
		}
		void operator ++() {
			pos++;
		}
	};

public:
	iterator begin() {
		return iterator(datos, 0);
	}
	iterator end() {
		return iterator(datos,datos.size());
	}
	vector<Node*> getDatos() {
		return datos;
	}
	void añadirDatos(Node* f) {
		datos.push_back(f);
		
	}
	void clear() {
		datos.clear();
	}
};