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

	DataFrame *a;
	DataFrame *b;

public:

	void leerDatos() {
		ifstream f("archivo.txt");
		string line, num;
		vector<int> enteros;
		vector<double> decimales;
		vector<string> palabras;
		if(!f.is_open()){
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (f >> line){
				stringstream ss(line);
				getline(ss, num, ',');
				//definetype
				if ((num[0] >= 65 && num[0] <= 90)||(num[0] >= 97 && num[0] <= 122)){
					cout << "Es un string" << endl;
					palabras.push_back(num);
				}
				else{
					int aux = stoi(num);
					int aux2 = int(aux);
					if (aux != (double)aux2) {
						cout << "Es un double" << endl;
						decimales.push_back(aux);
					}
					else{
						cout << "Es un entero " << endl;
						enteros.push_back(aux2);
					}
				}
				if (!palabras.empty()){
					for (int i = 0; i < palabras.size(); i++) {
						cout << palabras[i] << endl;
					}
				}
				cout << endl;
				if (!enteros.empty()) {
					for (int i = 0; i < enteros.size(); i++) {
						cout << enteros[i] << endl;
					}
				}
				cout << endl;
				if (!decimales.empty()) {
					for (int i = 0; i < decimales.size(); i++) {
						cout << decimales[i] << endl;
					}
				}

			}
		}
	}
	void escribirDatos() {}
	void mostrarDataframe() {
	
	
	}
	void filtrar(char a1, string b1, int f) { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
		vector<Row> filas = a->filtrarDatos(a1, b1, f);
		for (int i = 0; i < filas.size(); i++) {
			b->añadirFila(filas[i]);
		}
	}


};
