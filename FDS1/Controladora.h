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
		
		vector<string> me;
		ifstream f("archivo.txt");
		string line, num;
		vector<string> nomb;
		bool nombres = false;
		DataFrame* a = new DataFrame();
		if (!f.is_open()) {
			cout << "El archivo no se logro abrir " << endl;
		}
		else {
			while (getline(f,line)) {
				if (nombres == false) {
					stringstream ss(line);
					while (getline(ss, num, ',')) {
						nomb.push_back(num);
					}
					nombres = true;
					a->setNombres(nomb);
				}
				else {
					
					stringstream ss(line);
					me.clear();
					while (getline(ss, num, ',')) {
						me.push_back(num);
					}
					vector<string > ay = a->getNombres();
					
					a->añadirFila(me);
					
				}
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
		vector<string> a = w->getNombres();
		for (auto f : a) cout << f << " ";
		cout << endl;
		for (auto r : *w) {
			for(int i = 0; i < a.size(); i++)
			cout << r->getData(a[i]) << " ";
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
	/*void escribirDatos(int f) {
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
	*/
	void filtrar(int selec,string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
		cout << nc1 << " " << op1 << " " << val1 << " " << nc2 << " " << op2 << " " << val2 << endl;
		DataFrames.push_back(new DataFrame);
		DataFrames[DataFrames.size()-1] = DataFrames[selec-1]->filter(nc1, op1, val1, nc2, op2, val2);
	}
	void seleccionar(int selec, vector<string> names) {
		DataFrames.push_back(new DataFrame);
		DataFrames[DataFrames.size() - 1] = DataFrames[selec - 1]->select(names);
	}
	//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR
		//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR
		//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR//POR MODIFICAR

	//void indexar(int selec, string colName) {
	//    DataFrames.push_back(DataFrames[selec - 1]->indexar(colName));
	//}
	//
	void indexar(int selec, string colName) {
		DataFrames[selec - 1]->indexar(colName);
	}
};