#pragma once

#include "bus.h"
#include "garage.h"
#include "car.h"
#include "moto.h"
#include "keeper.h"
#include <iostream>
using std::cout;
using std::cin;

short num;

bool check_input()
{
	if (!cin.good())
	{
		cout << "Incorrect value entered." << endl;
		system("pause");
		cin.clear();
		while (cin.get() != '\n') {}
		
		return false;
	}
	return true;
}

void menu()
{
	while (1)
	{
		system("cls");
		cout << "The main menu:" << endl << endl;
		cout << "1. Input object" << endl;
		cout << "2. Delete object" << endl;
		cout << "3. Delete all objects" << endl;
		cout << "4. Save" << endl;
		cout << "5. Load" << endl;
		cout << "6. Print" << endl;
		cout << "0. Exit" << endl;
		cout << "Select an action: ";
		cin >> num;
		if (!check_input())
			continue;
		break;
	}
}

void dop_menu(Keeper* keeper)
{
	short num2;
	while (1)
	{
		system("cls");
		cout << "Dop menu" << endl;
		cout << "1. Input car " << endl;
		cout << "2. Input moto" << endl;
		cout << "3. Input bus" << endl;
		cout << "4. Exit" << endl;
	
		cout << "Input value";
		cin >> num2;
		if (!check_input())
			continue;
		switch (num2)
		{
		case 1:
		{
			garage* obj = new cars;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 2:
		{
			garage* obj = new motos;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 3:
		{
			garage* obj = new buses;
			obj->set();
			keeper->push(obj);
			continue;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "Invalid value entered." << endl;
			system("cls");
			continue;
		}
		}
		break;
	}
}

void LoadData()
{
	Keeper* keeper = new Keeper;
	while (1)
	{
		menu();
		switch (num)
		{
		case 1:
		{
			dop_menu(keeper);
			continue;
		}
		case 2:
		{
			if (!(keeper->pop()))
			{
				cout << "The list is empty, there is nothing to delete." << endl;
				system("pause");
			}
			continue;
		}
		case 3: {
			if (keeper->pop_all()) {
				cout << "All objects was delete. The list is empty." << endl;
			}
			else
				cout << "The list is empty, there is nothing to delete." << endl;
			system("pause");
			continue;
		}
		case 4:
		{

			system("cls");
			int ans;
			try {
				if (keeper->get_size() == 0)
					throw exception("Данных для сохранения недостаточно");
				cout << "1. Supplement the existing list.\n2. Overwrite the list." << endl;
				cin >> ans;
				if (!check_input())
				{
					cout << "Return to the main menu." << endl;
					system("pause");
					continue;
				}
				switch (ans)
				{
				case 1:
				{
					if (keeper->save_all())
					{
						cout << "The save was successful." << endl;
						system("pause");
					}
					break;
				}
				case 2:
				{
					if (remove("garage.txt") != 0)
						cout << "A deletion error has occurred. Most likely the file does not exist.";
					else
					{
						if (keeper->save_all())
							cout << "The save was successful." << endl;
					}
					system("pause");
					break;
				}
				default:
				{
					cout << "error 404 :)" << endl;
					system("pause");
					break;
				}
				}
				continue;
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
				system("pause");
				continue;
			}
				/*if (keeper->get_size() == 0)
				{
					cout << "The list is empty, there is nothing to save." << endl;
					system("pause");
					continue;
				}*/
				
		}
		
		case 5:
		{
			if ((keeper->recover_all()) != -1)
				cout << "The download was successful" << endl;
			else
				cout << "The file is empty." << endl;
			system("pause");
			continue;
		}
		case 6:
		{
			system("cls");
			keeper->show();
			system("pause");
			continue;
		}
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Incorrect number entered. Enter a number from 0 to 5." << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}