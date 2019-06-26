#pragma once

#include <vector>
#include <string>
#include <map>
#include "Column.h"


using namespace std;

class Row {
	
public:
	Row(map<string, Column*>* cols, int ind) : cols(cols), indice(ind) {
	
	}
	string getData(string name) {
		return (*cols)[name]->getDatos(indice);
	}
private:
	map<string, Column*>*cols;
	int indice;

};