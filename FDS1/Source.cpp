#include <iostream>
#include <conio.h>
#include "DataFrame.h"
#include "Controladora.h"

using namespace std;
using namespace System;

void mostrarm2(Controladora*& control) {
	int col, opcion;
	cout << "Ingrese columna: " << endl;
	cin >> col;
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
	cout << "                         *         6.- Esta contenido en.                                          *" << endl;
	cout << "                         *         7.- No está contenido en.                                       *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;

	do {
		cin >> opcion;
		cout << "Tipo: ";
		string tipo; cin >> tipo;
		switch (opcion) {
		case 1:; control->filtrar('>',tipo,col) ; break;
		case 2:; control->filtrar('<',tipo,col); break;
		case 3:; control->filtrar('=',tipo,col); break;
		case 4:; control->filtrar('0',tipo,col); break;
		case 5:; control->filtrar('n',tipo,col); break;
		case 6:; control->filtrar('>',tipo,col); break;
		default: control->filtrar('>',tipo,col); break;
		}
	} while (opcion == 0);
	
}
void showM() {
	cout << endl << endl << endl << endl << endl;
	cout << "                         ***************************************************************************" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                 MENU                                    *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *        1.- Importar                                                     *" << endl;
	cout << "                         *        2.- mostrar1                                                     *" << endl;
	cout << "                         *        3.- Exportar                                                     *" << endl;
	cout << "                         *        4.- Filtrar                                                      *" << endl;
	cout << "                         *        5.- mostrar2                                                     *" << endl;
	cout << "                         *        6.- Ordenar columna                                              *" << endl;
	cout << "                         *        7.- Salir                                                        *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;
}
void main() {
	Controladora* control = new Controladora();
	int opcion = 0;
	showM();
	do {
		cin >> opcion;
		switch (opcion) {
		case 1:control->leerDatosString(); opcion = 0; break;
		case 2:; control->mostrar(1); opcion = 0; break;
		case 3:; opcion = 0; break;
		case 4:  mostrarm2(control); opcion = 0; break;
		case 5:; control->mostrar(2); opcion = 0; break;
		case 6:; opcion = 0; break;
		case 7:; exit(1); break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);

	control->leerDatos();

	_getch();
}