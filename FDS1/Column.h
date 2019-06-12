#pragma once
#include <vector>
#include <string>
using namespace std;

class Column {
public:
	Column() {

	}
private:
	struct Node {
		string elem;
	};
	vector<Node*> datos;

	class iterator {
		Node* ptr;
		unsigned int pos;
	
	public:
		iterator(unsigned int pos) : pos(pos) {}
		iterator() : ptr(nullptr), pos(0) {}
		bool operator != (iterator other) {
			return this->pos != other.pos;
		}
		string operator *(vector<Node*> datos) {
			return datos[pos]->elem;
		}
		void operator ++() {
			pos++;
		}
	};
	
public:
	iterator begin() {
		return iterator(0);
	}
	iterator end() {
		return iterator(datos.size());
	}
	void añadirDatos(Node* a) {
		datos.push_back(a);
	}

};