#pragma once
#include<iostream>
#include<chrono>
#include"lista_sasiedztw.h"

struct smallNode
{
	smallNode* prev;
	smallNode* next;
	int val;
};
class ListaOneDirect
{
private:
	smallNode * head = nullptr;
	smallNode * tail = nullptr;
	int length=0;
public:
	~ListaOneDirect();
	void dodajkon(int x);
	void odejmijpocz();
	int getNode();
	int getLength();
	bool wyszukiwanie(int y);
};