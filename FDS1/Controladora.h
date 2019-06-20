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

	vector<DataFrame*> DataFrames;
public:
	
	Controladora() {
		
	}

	void leerDatosString() {
		DataFrame* a = new DataFrame;
		Row me;
		ifstream f("archivo.txt");
		string line, num;
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (getline(f,line)) {
				stringstream ss(line);
				//hola
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
		DataFrames.push_back(a);
	}
	void mostrar(int f) {
		mostrarDataFrame(DataFrames[f-1]);
	}
	void ListarDF() {
		cout << "-------------------------------------------" << endl;
		for (int i = 1; i <= DataFrames.size(); i++) {
			cout <<"-DataFrame "<<i << "" << endl;
		}
	}
	void mostrarDataFrame( DataFrame* w) {
		for (auto r : *w) {
			for (auto p : r) {
				cout << p << " ";
			}
			cout << endl;
		}

	}
	void añadirDF(DataFrame *f) {
		DataFrames.push_back(f);
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
	void escribirDatos(int f) {
		vector<Row> aux = DataFrames[f]->getFilas();
		for (int i = 0; i < aux.size(); i++) {
			Row auxi = aux[i];
			vector<Node*> auxiliar = auxi.getDatos();
			for (int j = 0; j < auxiliar.size(); j++) {
				Node* naux = auxiliar[j];
				ofstream archi2("archivo2.txt");
				archi2 << naux->getElem();
				archi2 << endl;
			}
		}
	}

	void filtrar(char a1, string b1, int f, int a) { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
	    vector<Row> filas = DataFrames[a-1]->filtrarDatos(a1, b1, f);
		DataFrame* wi = new DataFrame;
	    for (int i = 0; i < filas.size(); i++) {
	        wi->añadirFila(filas[i]);
	    }
		DataFrames.push_back(wi);
	}


};