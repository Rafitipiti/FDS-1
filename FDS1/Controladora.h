#pragma once

#include "DataFrame.h"
#include <fstream>

using namespace std;

template<typename T>
class Controladora {
private:

	DataFrame *a;
	DataFrame *b;

public:

	void leerDatos();
	void escribirDatos();
	void mostrarDatafraime();

};
