#ifndef ELECTRICNET_H
#define ELECTRICNET_H

#include "ElectricDevice.h"

class ElectricNet
{
public:
    ElectricNet(int = 0);
    ElectricNet(const ElectricNet &);
    ElectricNet &operator=(const ElectricNet &);

    //operators returning obj by ref (in this task not needed)
    //ElectricNet &operator+(const ElectricDevice &);
    //ElectricNet &operator+=(const ElectricDevice &);

    //ElectricNet & operator -(const ElectricDevice &);
    //ElectricNet & operator -=(const ElectricDevice &);

    void operator+(const ElectricDevice &);
    void operator+=(const ElectricDevice &);

    void operator-(const ElectricDevice &);
    void operator-=(const ElectricDevice &);

    ElectricDevice &operator[](const char *);

    bool operator!();

    //prefix and postfix operators
    //in this case void (Task eoesn't require them to be of other type)
    void operator++() { maxConsumption *= 2; }
    void operator++(int param) { maxConsumption *= 2; }

    void operator--() { maxConsumption /= 2; }
    void operator--(int param) { maxConsumption /= 2; }

    int getMaxConsumption() const { return maxConsumption; }
    void print() const;

    ~ElectricNet();

private:
    ElectricDevice *devices;
    int currentConsumption, maxConsumption;
    int size, capacity;

    void resize();
    void setMaxConsumption(int);
    bool empty() const;
    bool full() const;
};

#endif