#pragma once
#include <vector>
#include <string>
using namespace std;

class Column  {
public:
	Column() {

	}
private:
	
	vector<string> datos;

public:
	void añadirDatos(string a) {
		datos.push_back(a);
	}
	string getDatos( int a) {
		return datos[a];
	}
	void clear() {
		datos.clear();
	}
};