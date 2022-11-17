#include "moto.h"
#include <iostream>

using namespace std;

void motos::data()
{
	cout << "Марка: " << markamoto << endl;
	cout << "Модель: " << modelmoto << endl;
	cout << "Объем двигателя: " << dvigmoto << endl;
	cout << "Мощность двигателя: " << mowdvigmoto << endl;
	cout << "Местность для мотоцикла: " << mestnmoto << endl;

}

void motos::set()
{
	while (1)
	{
		system("cls");
		cout << "Введите марку мотоцикла: ";
		cin >> markamoto;
		if (exception(markamoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите модель мотоцикла: ";
		cin >> modelmoto;
		if (exception(modelmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите объем двигателя мотоцикла: ";
		cin >> dvigmoto;
		if (exception(dvigmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите мощность двигателя мотоцикла: ";
		cin >> mowdvigmoto;
		if (exception(mowdvigmoto) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите местность для которой предназначен мотоцикл: ";
		cin >> mestnmoto;
		if (exception(mestnmoto) == -2)
			continue;
		break;
	}
}

void motos::recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			markamoto = line;
			break;
		}
		case 1:
		{
			modelmoto = line;
			break;
		}

		case 2:
		{
			dvigmoto = line;
			break;
		}
		case 3:
		{
			mowdvigmoto = line;
			break;
		}
		case 4:
		{
			mestnmoto = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void motos::save(ofstream& out)
{
	out << 2 << endl;
	out << markamoto << endl;
	out << modelmoto << endl;
	out << dvigmoto << endl;
	out << mowdvigmoto << endl;
	out << mestnmoto << endl;
}

motos::motos()
{
	markamoto = "Пусто";
	modelmoto = "Пусто";
	dvigmoto = "Пусто";
	mowdvigmoto = "Пусто";
	mestnmoto = "Пусто";
}

motos::motos(string marka, string model, string dvig, string mowdvig, string mestn)
{
	this->markamoto = marka;
	this->modelmoto = model;
	this->dvigmoto = dvig;
	this->mowdvigmoto = mowdvig;
	this->mestnmoto = mestn;
}

motos::motos(const motos& Motos) :
	markamoto(Motos.markamoto), modelmoto(Motos.modelmoto), dvigmoto(Motos.dvigmoto), mowdvigmoto(Motos.mowdvigmoto), mestnmoto(Motos.mestnmoto) {}

motos::~motos() {}

int motos::exception(string line)
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
