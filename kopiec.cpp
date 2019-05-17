#include"kopiec.h"

Kopiec::~Kopiec()
{
	if(tab_len)
		delete[] tab;
}

Kopiec::Kopiec()
{
}

Kopiec::Kopiec(int _tab_len)
{
	tab = new Node[_tab_len];
}

void Kopiec::dodaj(Node x)
{
	tab[tab_len] = x;
	tab_len++;

	int fat_indx = (tab_len - 2) / 2;
	int curr_son_indx = tab_len - 1;
	Node temp;

	while (tab[fat_indx].w>tab[curr_son_indx].w)
	{
		temp = tab[curr_son_indx];
		tab[curr_son_indx] = tab[fat_indx];
		tab[fat_indx] = temp;
		curr_son_indx = fat_indx;
		fat_indx = (curr_son_indx - 1) / 2;
		if (fat_indx < 0) fat_indx = 0;
	}
}

Node Kopiec::usun()
{
	Node removed_elem;
	//usuwanie
	if (tab_len)
	{
		removed_elem = tab[0];
		Node* temp_tab;
		tab[0] = tab[tab_len - 1];
		temp_tab = new Node[tab_len - 1];
		tab_len--;
		for (int i = 0; i < tab_len; i++)
			temp_tab[i] = tab[i];
		delete[] tab;
		tab = temp_tab;
	}
	//naprawianie
	Node temp;
	switch (tab_len)
	{
	case 0:
	{
		//kopiec pusty
	}break;
	case 1:
	{
		//nie rob nic
	}break;
	case 2:
	{
		if (tab[1].w < tab[0].w)
		{
			temp = tab[0];
			tab[0] = tab[1];
			tab[1] = temp;
		}
	}break;
	default:
	{
		int j=1,k=2, index = 0;
		while (j < tab_len) {
			
			if (tab[j].w < tab[index].w) {
				
				if (k < tab_len && tab[k].w < tab[j].w) {
					
					std::swap(tab[index], tab[k]);

					// dla nastepnej iteracji
					index = k;
					
				}
				else {
					
					std::swap(tab[index], tab[j]);

					
					index = j;
				}

			} 
			else if (k < tab_len && tab[k].w < tab[index].w) {
				
				std::swap(tab[index], tab[k]);

					
					index = k;
			}
			else 
				break;
			j = 2 * index + 1;
			k = j + 1;
		}
		
	}break;
	}
	return removed_elem;
}

void Kopiec::show()
{
	int x,count=0,space_len,temp;
	while(count<tab_len)
	{
		x = log2(count+1);
		temp = pow(2, x);
		std::cout << x << ". ";
		space_len = (200 - temp) / (temp + 1);
		for (int j = 0; j < temp; j++)
		{
			for (int s = 0; s < space_len; s++)
				std::cout << ' ';
			std::cout << tab[count].Vp << ':' << tab[count].Vk << ':';
			if (tab[count].w == INT_MAX-1000)
				std::cout << "oo";
			else
				std::cout << tab[count].w;
			count++;
			if (count >= tab_len)
				break;
		}
		std::cout << std::endl;
	}
}

Node Kopiec::getElem(int x)
{
	return tab[x];
}

void Kopiec::modifythird(int a, int x)
{
	tab[x].Vk = a;
}

void Kopiec::modifysecond(int a, int x)
{
	tab[x].w = a;
}

int Kopiec::find(int x)
{
	for (int i = 0; i < tab_len; i++)
		if (tab[i].Vp == x)
			return i;
	return -1;
}

void Kopiec::addMemory(int x)
{
	Node *temp = new Node[tab_len+x];
	for (int i = 0; i < tab_len; i++)
		temp[i] = tab[i];
	if(tab_len-x>0)
		delete[]tab;
	tab = temp;
}

int Kopiec::getLength()
{
	return tab_len;
}
