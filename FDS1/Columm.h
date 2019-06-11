#pragma once

#include <vector>

using namespace std;


class Columm {
private:
	struct Node {
		string elem;
	};
	vector<string> datos;

	class iterator {

		unsigned int pos;
	public:
		iterator(unsigned int pos) : pos(pos) {}
		iterator() : ptr(nullptr), pos(0) {}
		bool operator != (iterator other) {
			return this->pos != other.pos;
		}
		T operator *() {
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
		return iterator(size);
	}
	void añadirDatos(Node a) {
		datos.push_back(a);
	}

};