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
	vector<string> nombresDFS;
public:
	
	Controladora() {
		
	}

	void leerDatosString(string b, char c) {
		nombresDFS.push_back(b);
		b += ".txt";
		vector<string> me;
		ifstream f(b);
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
					while (getline(ss, num, c)) {
						nomb.push_back(num);
					}
					nombres = true;
					a->setNombres(nomb);
				}
				else {
					
					stringstream ss(line);
					me.clear();
					while (getline(ss, num, c)) {
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
			cout << "Dataframe " << i << endl;
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
	void mostrarF(vector<Row*>* w, DataFrame* a) {
		vector<string> f = a->getNombres();
		if (w->size() == 0) {
			cout << "No se ha encontrado el elemento" << endl;
			return;
			for (auto r : *w) {
				for (int i = 0; i < f.size(); i++)
					cout << r->getData(f[i]) << " ";
				cout << endl;
			}
		}
	}
	void añadirDF(DataFrame *f){
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
	void escribirDatos(int w, string nombre, char separador) {
		ofstream archi2(nombre);
			vector<string> a = DataFrames[w]->getNombres();
			for (auto f : a) archi2 << f << separador;
			archi2 << endl;
			for (auto r : *DataFrames[w]) {
				for (int i = 0; i < a.size(); i++)
					archi2 << r->getData(a[i]) << separador;
				archi2 << endl;
			}
	}
	

	void filtrar(int selec,string nc1, string op1, string val1, string nc2 = "", string op2 = "", string val2 = "") { // f sera la columna / lo cambiaremos por "edad", "nombre" etc....
		cout << nc1 << " " << op1 << " " << val1 << " " << nc2 << " " << op2 << " " << val2 << endl;
		DataFrames.push_back(new DataFrame);
		DataFrames[DataFrames.size()-1] = DataFrames[selec-1]->filter(nc1, op1, val1, nc2, op2, val2);
	}
	void seleccionar(int selec, vector<string> names) {
		DataFrames.push_back(new DataFrame);
		DataFrames[DataFrames.size() - 1] = DataFrames[selec - 1]->select(names);
	}
	void indexar(int selec, string colName) {
		DataFrames[selec-1]->indexar(colName);
	}
	void ordenar(int selec, string colName) {
		if (!DataFrames[selec - 1]->ConsultarIndx(colName)) {
			indexar(selec, colName);
		}
		DataFrames.push_back(new DataFrame);
		DataFrames[DataFrames.size() - 1] = DataFrames[selec - 1]->sort(colName);
	}
	void buscarf(int selec, string colName, string elem) {
		if (!DataFrames[selec - 1]->ConsultarIndx(colName)) {
			indexar(selec, colName);
		}
		vector<Row*>* a = DataFrames[selec - 1]->Buscarf(colName ,elem);
		mostrarF(a, DataFrames[selec - 1]);
	}
};