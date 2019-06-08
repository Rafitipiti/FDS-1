#pragma once

#include "Columm.h"
#include "Row.h"
#include <vector>

using namespace std;

template<typename T>
class DataFrame {
private:

	Row *Filas;
	Columm *Columnas;

public:

	void filtrarDatos();
	void ordenarDatos();
	void editarDatos();

};
