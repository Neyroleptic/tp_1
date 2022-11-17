#pragma once
#include <string>
#include "garage.h"

using namespace std;

class buses : public garage
{
private:
	string markabus;
	string modelbus;
	string kolvosid;
	string kolvomest;
	string konpunkt;
public:
	virtual void data() override;
	virtual void set() override;
	virtual void recover(ifstream& in) override;
	virtual void save(ofstream& out) override;
	buses();
	buses(string mb, string mob, string kos, string kom, string kop);
	buses(const buses& Buses);
	int exception(string line);
	~buses();
};