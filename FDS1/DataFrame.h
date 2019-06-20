#pragma once
#include "Column.h"
#include "Row.h"
#include <vector>
using namespace std;

class DataFrame {
private:
	vector<Row> Filas;
	vector<Column> Columnas;
	int elementos;
	int n;
	string q;
	int r; 
	int fd;
	class iterator {
		unsigned int pos;
		vector<Row> f;
	public:

		iterator(vector<Row> f, unsigned int pos) : f(f), pos(pos) {}
		iterator(vector<Row> f) : pos(0) {}
		bool operator != (iterator other) {
			return this->pos != other.pos;
		}
		Row operator *() {
			return f[pos];
		}
		void operator ++() {
			pos++;
		}
	};

public:
	DataFrame() {

	}
	iterator begin() {
		return iterator(Filas, 0);
	}
	iterator end() {
		return iterator(Filas, Filas.size());
	}
	/*
	class iterator {
		unsigned int pos;
		vector<Column> f;
	public:

		iterator(vector<Column> f, unsigned int pos) : f(f), pos(pos) {}
		iterator(vector<Column> f) : pos(0) {}
		bool operator != (iterator other) {
			return this->pos != other.pos;
		}
		Column operator *() {
			return f[pos];
		}
		void operator ++() {
			pos++;
		}
	};

public:
	DataFrame() {
		
	}
	iterator begin() {
		return iterator(Columnas, 0);
	}
	iterator end() {
		return iterator(Columnas, Columnas.size());
	}
	*/
	void añadirFila(Row a) {

		Filas.push_back(a);
		
		vector<Node*> pff = a.getDatos();

		n = pff.size();
		Columnas.resize(n);
		//cout << "help";

		for (int i = 0; i < pff.size(); i++) {
			Columnas[i].añadirDatos(pff[i]);
		}
	}
	void editar() {

	}
	void ordenarDatos(){}
	void editarDatos(){}
	void clear() {
		for (auto f : Filas) {
			f.clear();
		}
		Filas.clear();
		for (auto f : Columnas) {
			f.clear();
		}
		Columnas.clear();
	}
	vector<Row> filtrarDatos(char c, string b, int f) { // f sera la columnas lo remplazaremos por un string mas adelante
		vector<Row> filas2;
		vector<Node*> eCol = Columnas[f].getDatos();
	
		switch (c) {
		case '>':
			r = stoi(b);
			for (int i = 0; i < eCol.size(); i++) {
				fd = stoi(eCol[i]->getElem());
			
				if (fd > r) {
					filas2.push_back(Filas[i]);
				}
			}
			break;
		case '<':
			r = stoi(b);
			for (int i = 0; i < eCol.size(); i++) {
				fd = stoi(eCol[i]->getElem());
				if (fd < r) {
					filas2.push_back(Filas[i]);
				}
			}
			break;
		case '=':
			r = stoi(b);
			for (int i = 0; i < eCol.size(); i++) {
				fd = stoi(eCol[i]->getElem());
				if (fd == r) {
					filas2.push_back(Filas[i]);
				}
			}
			break;
		case '0':
			for (int i = 0; i < eCol.size(); i++) {
				q = eCol[i]->getElem();
				if (b[0] == q[1]) {
					filas2.push_back(Filas[i]);
				}
			}
			break;
		case 'n':
			for (int i = 0; i < eCol.size(); i++) {
				q = eCol[i]->getElem();
				if (b[b.size()-1] == q[q.size()-1]) {
					filas2.push_back(Filas[i]);
				}
			}
			break;
		}
		
		return filas2;
	}

	vector<Row> getFilas() {
		return this->Filas;
	}
};
