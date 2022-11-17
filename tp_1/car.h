#pragma once
#include <string>
#include "garage.h"

using namespace std;

class cars : public garage
{
private:
    string markacar;
    string modelcar;
    string dvigcar;
    string cvetcar;
    string kppcar;
public:
    virtual void data() override;
    virtual void set() override;
    virtual void recover(ifstream& in) override;
    virtual void save(ofstream& out) override;
    cars();
    cars(string mc, string moc, string dvc, string cvc, string kc);
    cars(const cars& Cars);
    ~cars();
    int exception(string line);
};
