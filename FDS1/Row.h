#pragma once

#include <vector>

using namespace std;


class Row {

private:
	struct Node {
		string elem;

	};
	vector<Node> datos;
	int size;
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
	iterator begin() {
		return iterator( 0);
	}
	iterator end() {
		return iterator(size);
	}


	Node getAt(int a) {
		return datos[a];
	}
	string getE(int a) {
		return datos[a].elem;
	}

};