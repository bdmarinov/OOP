#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
public:
    Car();
    Car(const char *, const char *, const char *, int, int);
    Car(const Car &);
    Car &operator=(const Car &);

    void details() const override;
    ostream &format(ostream &) const override;
    istream &write(istream &) override;

    //friend ostream &operator<<(ostream &, const Car &);

    ~Car();
};

#endif