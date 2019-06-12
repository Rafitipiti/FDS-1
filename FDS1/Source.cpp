#include <iostream>
#include <conio.h>
#include "DataFrame.h"
#include "Controladora.h"

using namespace std;
using namespace System;

void mostrarm2() {
	int col, opcion;
	cout << "Ingrese columna: " << endl;
	cin >> col;
	Console::Clear();
	cout << endl << endl << endl << endl << endl;
	cout << "                         ***************************************************************************" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                 FILTRAR                                 *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *         1.- Mayor.                                                      *" << endl;
	cout << "                         *         2.- Menor.                                                      *" << endl;
	cout << "                         *         3.- Igual a.                                                    *" << endl;
	cout << "                         *         4.- Inicia con.                                                 *" << endl;
	cout << "                         *         5.- Finaliza con.                                               *" << endl;
	cout << "                         *         6.- Está contenido en.                                          *" << endl;
	cout << "                         *         7.- No está contenido en.                                       *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;

	do {
		cin >> opcion;
		switch (opcion) {
		case 1:; opcion = 0; break;
		case 2:; opcion = 0; break;
		case 3:; opcion = 0; break;
		case 4:; opcion = 0; break;
		case 5:; opcion = 0; break;
		case 6:; opcion = 0; break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);
	Console::Clear();
}

void main() {
	int opcion = 0;
	cout << endl << endl << endl << endl << endl;
	cout << "                         ***************************************************************************" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                 MENU                                    *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *        1.- Importar                                                     *" << endl;
	cout << "                         *        2.- Indexar                                                      *" << endl;
	cout << "                         *        3.- Exportar                                                     *" << endl;
	cout << "                         *        4.- Filtrar                                                      *" << endl;
	cout << "                         *        5.- Seleccionar                                                  *" << endl;
	cout << "                         *        6.- Ordenar columna                                              *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;
	do {
		cin >> opcion;
		switch (opcion) {
		case 1:; opcion = 0; break;
		case 2:; opcion = 0; break;
		case 3:; opcion = 0; break;
		case 4: Console::Clear(); mostrarm2(); opcion = 0; break;
		case 5:; opcion = 0; break;
		case 6:; opcion = 0; break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);
	
	Controladora *control;
	control->leerDatos();

	_getch();
}