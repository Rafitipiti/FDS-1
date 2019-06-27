#include <iostream>
#include <conio.h>
#include "DataFrame.h"
#include "Controladora.h"

using namespace std;
using namespace System;
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
	cout << "                         *        8.- Ordenar DF                                                   *" << endl;
	cout << "                         *        9.- Buscar fila                                                  *" << endl;
	cout << "                         *        10.- Salir                                                       *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         *                                                                         *" << endl;
	cout << "                         ***************************************************************************" << endl;
}
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
	if (seleccionado == 0) {
		return;
	}
	Console::ForegroundColor = ConsoleColor::Magenta;
	int col, opcion;
	cout << "Ingrese el numero de filtros " << endl;
	int num; cin >> num;
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
	Console::ForegroundColor = ConsoleColor::Red;
	Console::Clear(); showM(); cout << "Se ha creado un nuevo Dataframe" << endl;
}


void mostrarm2(Controladora*& control) {
	int opcion;
	cout << "Seleccione Dataframe "; cin >> opcion;
}
void mostrarm3(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
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
void buscarfila(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
	string n, elem;
	cout << "Ingrese el nombre de la columna por la cual desea buscar" << endl;
	cin >> n;
	cout << "Ingrese elemento a buscar" << endl;
	getline(cin, elem);
	getline(cin, elem);
	control->buscarf(seleccionado, n, elem);
	return;
}
void mostrarMOrd(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
	Console::ForegroundColor = ConsoleColor::DarkBlue;
	cout << "Ingrese el nombre de la columna por la cual desea ordenar" << endl;
	string a; cin >> a;
	control->ordenar(seleccionado, a);
	Console::ForegroundColor = ConsoleColor::Red;
	cout << "Se ha ordenado correctamente en un nuevo Dataframe " << endl;
}
void mostrarMSelec(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
	Console::ForegroundColor = ConsoleColor::Gray;
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
	cout << "Se ha creado un nuevo Dataframe" << endl;
	Console::ForegroundColor = ConsoleColor::Red;
}
void mostrarIndx(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
	cout << "Ingrese el nombre de la columna a indexar" << endl;
	string b; cin >> b;
	control->indexar(seleccionado, b);
	cout << "Se ha indexado la columna " << b << endl;
}
void mostrarMCarg(Controladora*& control) {
	Console::ForegroundColor = ConsoleColor::Cyan;
	cout << "Ingrese el nombre del archivo a cargar" << endl;
	string b; cin >> b;
	cout << "Ingrese el separador del archivo" << endl;
	cout << "1) CSV" << endl;
	cout << "2) TSV" << endl;
	cout << "3) Personalizado" << endl;
	string c; cin >> c;
	char we;
	switch (c[0]) {
		case '1': we = ','; break;
		case '2': we = '	'; break;
		case '3':
		cout << "Ingrese el separador del archivo" << endl; cin >> we; break;
	}
	control->leerDatosString(b, we);
	Console::ForegroundColor = ConsoleColor::Red;
	Console::Clear(); showM();
	cout << "Se ha cargado un archivo" << endl;
}
void mostrarArch(Controladora*& control, int seleccionado) {
	if (seleccionado == 0) {
		return;
	}
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "1) CSV" << endl;
	cout << "2) TSV" << endl;
	cout << "3) Personalizado" << endl;
	string b; cin >> b;
	char we;
	switch(b[0]) {
	case '1': we = ','; break;
	case '2': we = '	'; break;
	case '3': cout << "Ingrese el separador que desea que tenga el archivo" << endl; cin >> we; break;
	}
	cout << "Ingrese el nombre que desea que tenga el archivo" << endl;
	string f; cin >> f;
	f += ".txt";
	control->escribirDatos(seleccionado - 1, f, we);
	Console::ForegroundColor = ConsoleColor::Red;
	Console::Clear(); showM(); cout << "Se ha creado un archivo" << endl;
}
void main() {
	Controladora* control = new Controladora();
	int opcion = 0;
	Console::ForegroundColor = ConsoleColor::Red;
	showM();
	int seleccionado = 0;
	do {
		cin >> opcion;
		Console::Clear(); showM();
		switch (opcion) {
		case 1: mostrarMCarg(control);  break;
		case 2: control->ListarDF(); cout << endl; cout << "Seleccione un DF" << endl; cin >> seleccionado; Console::Clear(); showM(); cout << "Dataframe seleccionado" << endl; break;
		case 3: control->mostrar(seleccionado); break;
		case 4: mostrarFiltro(control,seleccionado); break;
		case 5: mostrarIndx(control,seleccionado); break;
		case 6: mostrarArch(control, seleccionado); break;
		case 7: mostrarMSelec(control, seleccionado); break;
		case 8: mostrarMOrd(control, seleccionado); break;
		case 9: buscarfila(control, seleccionado);  break;
		case 10: exit(0);
		default: opcion = 0; break;
		}
		
		opcion = 0;
	} while (opcion == 0);
}


