#pragma once

#include "DataFrame.h"
#include <fstream>
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
	Controladora() {}

	void leerDatos() {
		ifstream f("datos.txt");
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
	//void filtrar(char a1, string b1, int f) { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
	//    vector<Row> filas = a->filtrarDatos(a1, b1, f);
	//    for (int i = 0; i < filas.size(); i++) {
	//        b->añadirFila(filas[i]);
	//    }
	//}


};