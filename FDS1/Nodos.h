#pragma once
#include <string>
using namespace std;

//clase base para el tipo de dato por columnas
class Node {
public:
	string elem;
	Node(string f) : elem(f) {
	}
	string getElem() {
		return elem;
	}
	void setElem(string p) {
		elem = p;
	}
	
};
/*
class NodeInt : public Node{
public:
	int elem;
	NodeInt(int elem) : elem(elem){	
	}
	int getElem() {
		return elem;
	}
};

class NodeLl : public Node {
public:
	long long elem;
	NodeLl(long long elem) : elem(elem) {
	}
	long long getElem() {
		return elem;
	}
};

class NodeString : public Node {
public:
	string elem;
	NodeString(string elem) : elem(elem) {
	}
	string getElem() {
		return elem;
	}
};

class NodeFloat : public Node {
public:
	float elem;
	NodeFloat(float elem) : elem(elem) {	}
	float getElem() {
		return elem;
	}
};
class NodeDouble : public Node {
public:
	double elem;
	NodeDouble(double elem) : elem(elem) {	}
	double getElem() {
		return elem;
	}
};
*/