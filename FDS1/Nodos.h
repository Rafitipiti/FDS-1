#pragma once
#include <string>
using namespace std;

//clase base para el tipo de dato por columnas
class Node {
public: 
	Node() {

	}
	//int tipo;
	
};

class NodeInt : public Node{
	int elem;
	NodeInt(int elem) : elem(elem){	}
	int getElem() {
		return elem;
	}
};

class NodeLl : public Node {
	long long elem;
	NodeLl(long long elem) : elem(elem) {	}
	long long getElem() {
		return elem;
	}
};

class NodeString : public Node {
	string elem;
	NodeString(string elem) : elem(elem) {	}
	string getElem() {
		return elem;
	}
};

class NodeFloat : public Node {
	float elem;
	NodeFloat(float elem) : elem(elem) {	}
	float getElem() {
		return elem;
	}
};
class NodeDouble : public Node {
	double elem;
	NodeDouble(double elem) : elem(elem) {	}
	double getElem() {
		return elem;
	}
};