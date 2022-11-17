#pragma once
#include "car.h"
#include "garage.h"
#include "bus.h"
#include "moto.h"
#include "element.h"

using namespace std;

class Keeper
{
private:
	element* tail;
	int size;
public:
	Keeper();
	Keeper(element* Tail, int Size);
	Keeper(const Keeper& keeper);
	int get_size();
	int pop();
	int pop_all();
	void push(garage* obj);
	int save_all();
	int recover_all();
	bool isempty();
	void show();
	~Keeper();
};
