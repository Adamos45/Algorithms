#include<iostream>
#include<fstream>
#include<string>
#include"macierz_sasiedztw.h"
#include"lista_sasiedztw.h"
#include"Kruskal.h"
#include"Dijkstra_Kopiec.h"
#include"Bellman.h"
#include"Prim.h"
#include<random>
#include<chrono>

using namespace std;
Tablica* macierz=nullptr;
Lista* lista=nullptr;
void loadFileArray(Tablica**,bool);
void loadFileList(Lista**, bool);
void generateGraphArray(double,int,bool);
void generateGraphList(double,int,bool);
int generator(int x)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, x);

	return dist(gen);
}

int main()
{
	ofstream zapis;
	zapis.open("pomiary.txt");
	short choice,choice1,choice2;
	while (true)
	{
		cout << "1.Min drzewo rozpinajace 2.Najkrotsza sciezka 3.Generuj 4.Wyjscie" << endl<<"Wybor: ";
		while (true)
		{
			cin >> choice;
			if (choice < 0 || choice>4)
				cout << "Niepoprawny wybor." << endl;
			else if (choice == 4)
			{
				exit(EXIT_SUCCESS);
			}
			else
				break;
		}
		if (choice == 3)
		{
			Kruskal*kruskal1;
			Bellman*bellman1;
			Prim*prim1;
			DijkstraKopiec*dijkstra1;
			Kruskal*kruskal2;
			Bellman*bellman2;
			Prim*prim2;
			DijkstraKopiec*dijkstra2;
			double t[8] = { 0,0,0,0,0,0,0,0 };
			int rozmiary[] = { 10,150,200,300 };
			double gestosci[] = { 0.99,0.50,0.75,0.99 };
			for(int k=0;k<1;k++)
			for (int z = 0; z < 1; z++)
			{
				for (int i = 0; i < 1; i++)
				{
					cout << i << endl;
					generateGraphArray(gestosci[z], rozmiary[k], true);
					generateGraphList(gestosci[z], rozmiary[k], true);
					macierz->ShowTab();
					cout << endl;
					lista->show();
					cout << endl;
					kruskal1 = new Kruskal(macierz);
					kruskal2 = new Kruskal(lista);
					bellman1 = new Bellman(macierz);
					bellman2 = new Bellman(lista);
					prim1 = new Prim(macierz);
					prim2 = new Prim(lista);
					dijkstra1 = new DijkstraKopiec(macierz);
					dijkstra2 = new DijkstraKopiec(lista);

					auto start = std::chrono::high_resolution_clock::now();
					kruskal1->Execute();
					auto stop = std::chrono::high_resolution_clock::now();
					chrono::duration<double>dur = stop - start;
					t[0] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					kruskal2->Execute();
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[1] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					bellman1->Execute(false);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[2] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					bellman2->Execute(true);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[3] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					prim1->Execute(false);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[4] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					prim2->Execute(true);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[5] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					dijkstra1->Execute(false);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[6] += dur.count();

					start = std::chrono::high_resolution_clock::now();
					dijkstra2->Execute(true);
					stop = std::chrono::high_resolution_clock::now();
					dur = stop - start;
					t[7] += dur.count();
					
					kruskal1->show();
					prim1->show();
					bellman1->show();
					dijkstra1->show();
					kruskal2->show();
					prim2->show();
					bellman2->show();
					dijkstra2->show();
					
					kruskal1->~Kruskal();
					kruskal2->~Kruskal();
					bellman1->~Bellman();
					bellman2->~Bellman();
					prim1->~Prim();
					prim2->~Prim();
					dijkstra1->~DijkstraKopiec();
					dijkstra2->~DijkstraKopiec();

					macierz->~Tablica();
					lista->~Lista();
				}
				zapis << "Rozmiar: " << rozmiary[k] << " Gestosc: " << gestosci[z] << endl
					<< t[0] / 100 << endl
					<< t[1] / 100 << endl
					<< t[2] / 100 << endl
					<< t[3] / 100 << endl
					<< t[4] / 100 << endl
					<< t[5] / 100 << endl
					<< t[6] / 100 << endl
					<< t[7] / 100 << endl;
				for (int i = 0; i < 8; i++)
					t[i] = 0;
			}
			continue;
		}
		cout << "Reprezentacja grafu. 1.Macierz 2.Lista"<<endl<<"Wybor: ";
		while (true)
		{
			cin >> choice1;
			if (choice1 < 0 || choice1>2)
				cout << "Niepoprawny wybor." << endl;
			else
				break;
		}
		if (choice == 1 && choice1 == 1)
		{
			loadFileArray(&macierz, true);
			macierz->ShowTab();
		}
		if (choice == 1 && choice1 == 2)
		{
			loadFileList(&lista, true);
			lista->show();
		}
		if (choice == 2 && choice1 == 1)
		{
			loadFileArray(&macierz, false);
			macierz->ShowTab();
		}
		if (choice == 2 && choice1 == 2)
		{
			loadFileList(&lista, false);
			lista->show();
		}

		if(choice==1)
			cout << "Wybierz algorytm. 1.Kruskala 2.Prima," << endl<<"Wybor: ";
		else
			cout << "Wybierz algorytm. 1.Dijkstry 2.Bellmana" << endl << "Wybor: ";

		while (true)
		{
			cin >> choice2;
			if (choice1 < 1 || choice1>2)
				cout << "Niepoprawny wybor" << endl;
			else
				break;
		}
		switch (choice)
		{
			case 1:
			{
				if (choice2 == 1)
				{
					Kruskal*kruskal;
					cout << "Wykonywanie Kruskal: " << endl;
					if (choice1 == 1)
						kruskal = new Kruskal(macierz);
					else
						kruskal = new Kruskal(lista);
					kruskal->Execute();
					kruskal->show();
					kruskal->~Kruskal();
					if (choice1 == 1)
						macierz->~Tablica();
					else
						lista->~Lista();
				}
				else
				{
					Prim*prim;
					cout << "Wykonywanie Prim"<<endl;
					if (choice1 == 1)
					{
						prim = new Prim(macierz);
						prim->Execute(false);
					}
					else
					{
						prim = new Prim(lista);
						prim->Execute(true);
					}
					prim->show();
				}
			}break;
			case 2:
			{
				if (choice2 == 1)
				{
					DijkstraKopiec* dijkstra;
					cout << "Dijkstra:" << endl;
					if (choice1 == 1)
					{
						dijkstra = new DijkstraKopiec(macierz);
						dijkstra->Execute(false);
					}
					else
					{
						dijkstra = new DijkstraKopiec(lista);
						dijkstra->Execute(true);
					}
					dijkstra->show();
					dijkstra->~DijkstraKopiec();
				}
				else
				{
					Bellman* bellman;
					cout << "Bellman-Ford" << endl;
					bool signed_cycle;
					if (choice1 == 1)
					{

						bellman = new Bellman(macierz);
						signed_cycle = bellman->Execute(false);
						bellman->~Bellman();

					}
					else
					{

						bellman = new Bellman(lista);
						signed_cycle = bellman->Execute(true);
						bellman->~Bellman();

					}

					if (signed_cycle)
						bellman->show();
					else
						cout << "Wykryto cykl ujemny. ";
					bellman->~Bellman();
				}
			}break;
			default:
			{
				cout << "Niepoprawny wybor" << endl;
			}
		}
	}
	cin.get();
	cin.get();
}

void loadFileArray(Tablica **macierz,bool is_MST)
{
	int find, find2;
	string stream, file_name;
	ifstream in;
	string num_txt;
	int a, b, c;
	bool first_line = true;
start:
	
	while (true)
	{
	cout << "Podaj nazwe pliku: ";
	cin >> file_name;
	file_name += ".txt";
	in.open(file_name, ios::in);
	if (in.good())
	break;
	else
	cout << "Nie znaleziono podanego pliku." << endl;
	}

	while (!in.eof())
	{
		getline(in, stream);
		find = stream.find_first_of("0123456789");
		if (find == string::npos)
			continue;
		find2 = stream.find(' ', find);
		if (find2 == string::npos)
			find2 = stream.size();

		if (first_line)
		{
			num_txt = stream.substr(find, find2 - find);
			int a, b, c, d;
			a = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.find(' ', find);
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			b = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.find(' ', find);
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			c = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.size() - find;
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			d = stoi(num_txt);
			*macierz = new Tablica(a, b, c, d);
			first_line = false;
			find = string::npos;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			in.close();
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		a = stoi(num_txt);
		find = stream.find_first_of("0123456789", find2);
		find2 = stream.find(' ', find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		b = stoi(num_txt);
		find = stream.find_first_of("-0123456789", find2);
		find2 = stream.find(' ', find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		c = stoi(num_txt);
		(*macierz)->LoadEdge(a, b, c);
		if(is_MST)
			(*macierz)->LoadEdge(b, a, c);
	}
	in.clear();
	in.seekg(0, ios::beg);
	first_line = true;
	cout << "Wczytano" << endl;
	in.close();
}
void loadFileList(Lista **lista, bool is_MST)
{
	int find, find2;
	string stream, file_name;
	ifstream in;
	string num_txt;
	int a, b, c;
	bool first_line = true;
start:
	
	while (true)
	{
		cout << "Podaj nazwe pliku: ";
		cin >> file_name;
		file_name += ".txt";
		in.open(file_name, ios::in);
		if (in.good())
			break;
		else
			cout << "Nie znaleziono podanego pliku." << endl;
	}
	
	while (!in.eof())
	{
		getline(in, stream);
		find = stream.find_first_of("0123456789");
		if (find == string::npos)
			continue;
		find2 = stream.find(' ', find);
		if (find2 == string::npos)
			find2 = stream.size();

		if (first_line)
		{
			num_txt = stream.substr(find, find2 - find);
			int a, b, c, d;
			a = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.find(' ', find);
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			b = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.find(' ', find);
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			c = stoi(num_txt);
			find = stream.find_first_of("0123456789", find2);
			find2 = stream.size() - find;
			if (find == string::npos)
			{
				cout << "Niewystarczaj¹ca ilosc danych startowych." << endl;
				in.close();
				goto start;
			}
			num_txt = stream.substr(find, find2 - find);
			d = stoi(num_txt);
			*lista = new Lista(a, b, c, d);
			first_line = false;
			find = string::npos;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			in.close();
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		a = stoi(num_txt);
		find = stream.find_first_of("0123456789", find2);
		find2 = stream.find(' ', find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		b = stoi(num_txt);
		find = stream.find_first_of("-0123456789", find2);
		find2 = stream.find(' ', find);
		if (find == string::npos)
		{
			cout << "Niewystarczajaca ilosc danych, ignorowanie linii." << endl;
			continue;
		}
		num_txt = stream.substr(find, find2 - find);
		c = stoi(num_txt);
		(*lista)->add(a, b, c);
		if (is_MST)
			(*lista)->add(b, a, c);
	}
	in.clear();
	in.seekg(0, ios::beg);
	first_line = true;
	cout << "Wczytano" << endl;
	in.close();
}
void generateGraphArray(double gestosc,int wierzcholki,bool directed)
{
	int nV=wierzcholki;
	macierz = new Tablica(0,nV, generator(nV-1), 0);
	
	int w = generator(10);
	int top = 0; //najwiekszy wierzcholek

	int nK=0; //ilosc krawedzi
	int x, y;
	double tGestosc=1.0; //obecna gestosc

	while (top != nV - 1)
	{
		w = generator(10);
		if (tGestosc > gestosc)
		{
			x = generator(top);
			top++;
			if(directed)
				macierz->LoadEdge(x, top, w);
			macierz->LoadEdge(top, x, w);
		}
		else
		{
			x = generator(top);
			do
			{
				y = generator(top);
			} while (x == y);
			while(true)
			{
				if (macierz->getValue(x, y) != INT_MAX-1000)
				{
					x = generator(top);
					do
					{
						y = generator(top);
					} while (x == y);
					continue;
				}
				if (macierz->getValue(y, x) != INT_MAX - 1000)
				{
					x = generator(top);
					do
					{
						y = generator(top);
					} while (x == y);
					continue;
				}
				break;
			}
			if(directed)
				macierz->LoadEdge(y, x, w);
			macierz->LoadEdge(x, y, w);
		}
		nK++;
		tGestosc = nK/((top+1)*((top+1) - 1) / 2.0);
	}
	macierz->setEn(nK);
}
void generateGraphList(double gestosc, int wierzcholki,bool directed)
{
	int nV = wierzcholki;
	lista = new Lista(0, nV, generator(nV-1), 0);

	int w = generator(10);
	int top = 0; //najwiekszy wierzcholek
	int x, y;
	int nK = 0; //ilosc krawedzi
	
	double tGestosc = 1.0; //obecna gestosc

	while (top != nV - 1)
	{
		w = generator(10);
		if (tGestosc > gestosc)
		{
			x = generator(top);
			top++;
			if (directed)
				lista->add(x, top, w);
			lista->add(top, x, w);
		}
		else
		{
			x = generator(top);
			do
			{
				y = generator(top);
			} while (x == y);
			tryAgain:
			int r = lista->getVertexSize(x);
			for (int i = 0; i < r; i++)
			{
				if (lista->getNode(x, i)->Vk == y)
				{
					x = generator(top);
					do
					{
						y = generator(top);
					} while (x == y);
					i = -1;
					r = lista->getVertexSize(x);
				}
			}
			int k = lista->getVertexSize(y);
			if(k!=0)
				for (int j = 0; j < k; j++)
				{
					if (lista->getNode(y, j)->Vk == x)
					{
						x = generator(top);
						do
						{
							y = generator(top);
						} while (x == y);
						r = lista->getVertexSize(x);
						j = k;
						goto tryAgain;
					}
				}
			if (directed)
				lista->add(y, x, w);
			lista->add(x, y, w);
		}
		nK++;
		tGestosc = nK / ((top + 1)*((top + 1) - 1) / 2.0);
	}
	lista->setEn(nK);
}