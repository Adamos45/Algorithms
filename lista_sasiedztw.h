#pragma once
#include<iostream>

struct Node
{
	int Vp;
	int Vk;
	int w;
	Node *prev;
	Node *next;
};
class Lista
{
private:
	Node** listArray=nullptr;
	int* listArraySizes=nullptr;
	int listSize=0;
	int En=-1;
	int Vn=-1;
	int Vp=-1;
	int Vk=-1;
public:
	Lista();
	~Lista();
	Lista(int _En, int _Vn, int _Vp, int _Vk);
	void add(int Vp, int Vk, int w);
	void show();
	Node* getNode(int x, int y);
	int getVertexSize(int V);
	int getListSize();
	int getVertexSize();
	int getStart();
	void setEn(int x);
};