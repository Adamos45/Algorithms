#pragma once
#include<iostream>

class Tablica
{
private:
	int **tab;
	int En=-1;
	int Vn=-1;
	int Vp=-1;
	int Vk=-1;

public:
	Tablica();
	~Tablica();
	Tablica(int _En, int _Vn, int _Vp, int _Vk);
	void LoadEdge(int _Vp, int _Vk, int _w);
	void ShowTab();
	int getRowSize();
	int getValue(int x, int y);
	int getEdgesNumber();
	int getStart();
	void setEn(int x);
};