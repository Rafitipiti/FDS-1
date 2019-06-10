#pragma once

#include "DataFrame.h"
#include <fstream>
#include <sstream>
#include <string>

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
				getline(ss, num);
				if ((num.c_str()[0] >= 65 && num.c_str()[0] <= 90)||(num.c_str()[0] >= 97 && num.c_str()[0] <= 122)){
					cout << "Es un string" << endl;
					palabras.push_back(num.c_str());
				}
				else{
					double aux = stoi(num.c_str());
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
	void mostrarDatafraime() {}


};
