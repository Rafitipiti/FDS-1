#pragma once

#include "DataFrame.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Column.h"
#include "Row.h"

using namespace std;


class Controladora {
private:

	DataFrame* a;
	DataFrame* b;

public:
	
	Controladora() {
		this->a = new DataFrame();
		this->b = new DataFrame();
	}

	void leerDatosString() {
		
		Row me;
		ifstream f("archivo.txt");
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (getline(f,line)) {
				stringstream ss(line);
				me.clear();
				while (getline(ss, num, ',')) {
					Node* q = new Node(num);
					//cout << num << endl;
					me.añadirDatos(q);
				}
				//for (auto a : me) cout << a << " ";
				//cout << endl;
				a->añadirFila(me);
			}
		}
	}
	void mostrar(int f) {
		if (f == 1) mostrarDataFrame(a);
		else mostrarDataFrame(b);
	}
	void mostrarDataFrame( DataFrame* w) {
		for (auto r : *w) {
			for (auto p : r) {
				cout << p << " ";
			}
			cout << endl;
		}

	}
	void leerDatos() {
		ifstream f("archivo.txt");
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (f >> line) {
				stringstream ss(line);
				getline(ss, num, ',');
				//definetype
				if ((num[0] >= 65 && num[0] <= 90) || (num[0] >= 97 && num[0] <= 122)) {
					cout << "Es un string" << endl;
				}
				else {
					double aux = stod(num);
					int aux2 = int(aux);
					if (aux != (double)aux2) {
						cout << "Es un double" << endl;
					}
					else {
						cout << "Es un entero " << endl;
					}
				}
			}
			cout << endl;
		}
	}
	void escribirDatos() {}
	void mostrarDataframe() {


	}
	void filtrar(char a1, string b1, int f) { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
	    vector<Row> filas = a->filtrarDatos(a1, b1, f);
		cout << filas.size() << endl;
		for (auto w : filas) {
			for (auto rf : w) {
				cout << rf << " ";
			}
			cout << endl;
		}
		b->clear();
	    for (int i = 0; i < filas.size(); i++) {
	        b->añadirFila(filas[i]);
	    }
	}


};