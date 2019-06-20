#include <iostream>
#include <conio.h>
#include "DataFrame.h"
#include "Controladora.h"

using namespace std;
using namespace System;
string tipo(int opcion) {
	switch (opcion) {
	case 1:; return ">"; break;
	case 2:; return "<"; break;
	case 3:; return "="; break;
	case 4:; return "0"; break;
	case 5:; return "n"; break;
	case 6:; return "z"; break;
	case 7:; return "x"; break;
	}
}
void mostrarFiltro(Controladora*& control, int seleccionado) {
	int col, opcion;
	cout << "Ingrese el numero de filtros " << endl;
	int num; cin >> num;
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
	cout << endl;
	if (num == 2) {
		cout << "Ingrese el filtro 1: " << endl;
		int f1; cin >> f1;
		cout << "Ingrese el nombre de la columna para el filtro 1: " << endl;
		string coln1; cin >> coln1;
		cout << "Ingrese el elemento base para el filtro 1: " << endl;
		string ele1; cin >> ele1;
		cout << "Ingrese el filtro 2: " << endl;
		int f2; cin >> f2;
		cout << "Ingrese el nombre de la columna para el filtro 2: " << endl;
		string coln2; cin >> coln2;
		cout << "Ingrese el elemento base para el filtro 2: " << endl;
		string ele2; cin >> ele2;
		control->filtrar(seleccionado, coln1, tipo(f1), ele1, coln2,tipo(f2),ele2);
	}
	else {
		cout << "Ingrese el filtro 1: " << endl;
		int f1; cin >> f1;
		cout << "Ingrese el nombre de la columna para el filtro 1: " << endl;
		string coln1; cin >> coln1;
		cout << "Ingrese el elemento base para el filtro 1: " << endl;
		string ele1; cin >> ele1;
		control->filtrar(seleccionado,coln1, tipo(f1), ele1);
	}
	
}

void mostrarm1(Controladora*& control) {
	int op;
	do {
		cout << "Seleccione tipo de separador (1: ' ' ; 2: ',')"; cin>>op;
	} while (!(op == 1 || op == 2));
	switch (op){
	case 1:control->leerDatosString(); break;
	case 2:control->leerDatosString(); break;
	default:
		break;
	}
}
void mostrarm2(Controladora*& control) {
	int opcion;
	cout << "Seleccione Dataframe "; cin >> opcion;
}
void mostrarm3(Controladora*& control, int seleccionado) {
	int opc;
	cout << "*************************************" << endl;
	cout << "*          CREAR DATAFRAME          *" << endl;
	cout << "*                                   *" << endl;
	cout << "*      1> Creacion desde cero       *" << endl;
	cout << "*      2> Desde otro Dataframe      *" << endl;
	cout << "*                                   *" << endl;
	cout << "*************************************" << endl;
	cout << endl;
	do {
		cout << "Ingrese la opcion : "; cin >> opc;
	} while (!(opc == 1 || opc == 2));
	switch (opc)
	{
	case 1:
		cout << endl;
		cout << " Columna " << endl;
		cout << " Fila    " << endl;
 		break;
	case 2:
		int op;
		cout << endl;
		cout << " 1 > Seleccionar Dataframe " << endl;
		cout << " 2 > Operaciones con Dataframe " << endl;
		do{
			cout << "Ingrese la opcion : "; cin >> op;
		} while (!(op == 1 || op == 2));
		if (op == 1) {
			cout << "-----------------" << endl;
			control->ListarDF();
			break;
		}
		else if (op == 2) {
			cout << endl;
			cout << " Seleccionar columna " << endl;
			cout << " Filtrar " << endl;
			mostrarFiltro(control, seleccionado);
		}
	default:
		break;
	}

}
void mostrarMSelec(Controladora*& control, int seleccionado) {
	cout << "Ingrese el numero de columnas del nuevo DF: " << endl;
	int a; cin >> a;
	cout << "Ingrese los nombres de columnas que desee que tenga el nuevo DF: " << endl;
	vector<string> b;
	string z;
	while (a--) {
		cin >> z;
		b.push_back(z);
	}
	control->seleccionar(seleccionado, b);
}
//void showM() {
//	cout << endl << endl << endl << endl << endl;
//	cout << "                         ***************************************************************************" << endl;
//	cout << "                         *                                                                         *" << endl;
//	cout << "                         *                                 MENU                                    *" << endl;
//	cout << "                         *                                                                         *" << endl;
//	cout << "                         *        1.- Importar                                                     *" << endl;
//	cout << "                         *        2.- mostrar1                                                     *" << endl;
//	cout << "                         *        3.- Exportar                                                     *" << endl;
//	cout << "                         *        4.- Filtrar                                                      *" << endl;
//	cout << "                         *        5.- mostrar2                                                     *" << endl;
//	cout << "                         *        6.- Ordenar columna                                              *" << endl;
//	cout << "                         *        7.- Salir                                                        *" << endl;
//	cout << "                         *                                                                         *" << endl;
//	cout << "                         ***************************************************************************" << endl;
//}

void showM() {
	cout << endl << endl << endl << endl << endl;
	cout << "                         ***************************************************************************" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                  MENU                                   *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *        1.- Cargar Dataframe                                             *" << endl;
	cout << "                         *        2.- Seleccionar Dataframe                                        *" << endl;
	cout << "                         *        3.- Mostrar Dataframe                                            *" << endl;
	cout << "                         *        4.- Filtrar Dataframe                                            *" << endl;
	cout << "                         *        5.- Indexar Dataframe                                            *" << endl;
	cout << "                         *        6.- Escribir Dataframe                                           *" << endl;
	cout << "                         *        7.- Seleccionar DF por columnas                                  *" << endl;
	cout << "                         *        8.- Salir                                                        *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;
}
void main() {
	Controladora* control = new Controladora();
	int opcion = 0;
	showM();
	int seleccionado;
	do {
		cin >> opcion;
		switch (opcion) {
		case 1:control->leerDatosString(); opcion = 0; break;
		case 2:control->ListarDF(); cout << endl; cout << "Seleccione un DF" << endl; cin >> seleccionado; opcion = 0; break;
		case 3:control->mostrar(seleccionado); opcion = 0; break;
		case 4:mostrarFiltro(control,seleccionado); opcion = 0; break;
		case 5:control->mostrar(2); opcion = 0; break;
//		case 6:control->escribirDatos(seleccionado); opcion = 0; break;
		case 7:mostrarMSelec(control, seleccionado); opcion = 0; break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);

	//control->leerDatos();

	_getch();
}
/*
void main() {
	Controladora* control = new Controladora();
	int opcion = 0;
	showM();
	do {
		cin >> opcion;
		switch (opcion) {
		case 1: mostrarm1(control); opcion = 0; break;
		case 2: mostrarm2(control); opcion = 0; break;
		case 3: control->mostrar(1); opcion = 0; break;
		case 4: mostrarm3(control); control->mostrar(2); opcion = 0; break;
		case 5: mostrarm2; break;
		case 6: exit(1); break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);

	control->leerDatos();

	_getch();
}
*/