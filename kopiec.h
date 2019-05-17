#pragma once
#include<iostream>
#include<fstream>
#include<chrono>
#include<algorithm>
#include"lista_sasiedztw.h"


class Kopiec
{
private:
	Node* tab;
	int tab_len=0;
public:
	Kopiec();
	Kopiec(int _tab_len);
	~Kopiec();
	void dodaj(Node x);
	Node usun();
	void show();
	Node getElem(int x);
	void modifythird(int a, int x);
	void modifysecond(int a, int x);
	int find(int x);
	void addMemory(int x);
	int getLength();
};