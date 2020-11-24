#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    Truck();
    Truck(const char *, const char *, const char *, int, int, int);
    Truck(const Truck &);
    Truck &operator=(const Truck &);

    void setSize(int);

    int getSize() const { return size; }

    void details() const override;
    ostream &format(ostream &) const override;

    ~Truck();

private:
    int size;
};

#endif