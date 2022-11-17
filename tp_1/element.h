#pragma once
#include "garage.h"

class element
{
private:
	garage* obj;
	element* prev;
public:
	garage* get_obj();
	element* get_prev();
	void set_obj(garage* Obj);
	void set_prev(element* Prev);
};
