#include "bus.h"
#include <iostream>
#include <cstring>


using namespace std;

void buses::data()
{
	cout << "Марка: " << markabus << endl;
	cout << "Модель: " << modelbus << endl;
	cout << "Кол-во сидячих мест: " << kolvosid << endl;
	cout << "Общее кол-во мест: " << kolvomest << endl;
	cout << "Конечный пункт: " << konpunkt << endl;
}

void buses::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите марку автобуса: ";
		cin >> markabus;
		if (exception(markabus) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите модель автобуса: ";
		cin >> modelbus;
		if (exception(modelbus) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите кол-во сидячих мест: ";
		cin >> kolvosid;
		if (exception(kolvosid) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите общее кол-во мест: ";
		cin >> kolvomest;
		if (exception(kolvomest) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите пункт назначения автобуса: ";
		cin >> konpunkt;
		if (exception(konpunkt) == -2)
			continue;
		break;
	}
}

void buses::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markabus = line;
			break;
		}
		case 1:
		{
			modelbus = line;
			break;
		}
		case 2:
		{
			kolvosid = line;
			break;
		}
		case 3:
		{
			kolvomest = line;
			break;
		}
		case 4:
		{
			konpunkt = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void buses::save(ofstream& out)
{
	out << 3 << endl;
	out << markabus << endl;
	out << modelbus << endl;
	out << kolvosid << endl;
	out << kolvomest << endl;
	out << konpunkt << endl;
}

buses::buses()
{
	markabus = "Пусто";
	modelbus = "Пусто";
	kolvosid = "Пусто";
	kolvomest = "Пусто";
	konpunkt = "Пусто";
}

buses::buses(string mb, string mob, string kos, string kom, string kop)
{
	this->markabus = mb;
	this->modelbus = mob;
	this->kolvosid = kos;
	this->kolvomest = kom;
	this->konpunkt = kop;

}

buses::buses(const buses& Buses) : markabus(Buses.markabus), modelbus(Buses.modelbus), kolvosid(Buses.kolvosid), kolvomest(Buses.kolvomest), konpunkt(Buses.konpunkt) {}

int buses::exception(string line)
{
	try
	{
		if (line.empty())
			throw - 2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "Данное поле не должно быть пустым" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "error 404" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}

buses::~buses() {}