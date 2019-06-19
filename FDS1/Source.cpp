#include <iostream>
#include <conio.h>
#include "DataFrame.h"
#include "Controladora.h"

using namespace std;
using namespace System;

void mostrarFiltro(Controladora*& control) {
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
void mostrarm3(Controladora*& control) {
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
			break;
		}
		else if (op == 2) {
			cout << endl;
			cout << " Seleccionar columna " << endl;
			cout << " Filtrar " << endl;
			mostrarFiltro(control);
		}
	default:
		break;
	}

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
	cout << "                         *                                  MENU                                    *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *        1.- Cargar Dataframe                                             *" << endl;
	cout << "                         *        2.- Guardar Dataframe                                            *" << endl;
	cout << "                         *        3.- Listar Dataframe                                             *" << endl;
	cout << "                         *        4.- Crear Dataframe                                              *" << endl;
	cout << "                         *        5.- Indexar Dataframe                                            *" << endl;
	cout << "                         *        6.- Escribir Dataframe B                                         *" << endl;
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
		case 2:control->mostrar(1); opcion = 0; break;
		case 3:opcion = 0; break;
		case 4:mostrarFiltro(control); opcion = 0; break;
		case 5:control->mostrar(2); opcion = 0; break;
		case 6:escribirDatosb(); opcion = 0; break;
		case 7:exit(1); break;
		default: opcion = 0; break;
		}
	} while (opcion == 0);

	control->leerDatos();

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