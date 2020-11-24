#ifndef ELECTRICDEVICE_H
#define ELECTRICDEVICE_H

#include <iostream>
#include <string.h>

using namespace std;

bool isEqual(const char*, const char *);

class ElectricDevice
{
public:
    ElectricDevice();
    ElectricDevice(const char *, int);
    ElectricDevice(const ElectricDevice &);
    ElectricDevice &operator=(const ElectricDevice &);

    void setName(const char *);
    void setPower(int);

    char *getName() const { return name; }
    int getPower() const { return power; }

    bool operator ==(const ElectricDevice &);

    friend ostream & operator <<(ostream &, const ElectricDevice &);
    friend istream & operator >>(istream &, ElectricDevice &);

    ~ElectricDevice();

private:
    char *name;
    int power;
};

#endif