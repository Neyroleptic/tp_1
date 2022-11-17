#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class garage
{
public:
	virtual void data() = 0;
	virtual void set() = 0;
	virtual void save(ofstream& out) = 0;
	virtual void recover(ifstream& in) = 0;
	virtual ~garage();
};
