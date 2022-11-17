#pragma once
#include <string>
#include "garage.h"

using namespace std;

class motos : public garage
{
private:
	string markamoto;
	string modelmoto;
	string dvigmoto;
	string mowdvigmoto;
	string mestnmoto;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	motos();
	motos(string marka, string model, string dvig, string mowdvig, string mestn);
	motos(const motos& Motos);
	~motos();
	int exception(string line);
};


