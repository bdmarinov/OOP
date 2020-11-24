#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle
{
public:
    Motorcycle();
    Motorcycle(const char *, const char *, const char *, int, int, const char *);
    Motorcycle(const Motorcycle &);
    Motorcycle &operator=(const Motorcycle &);

    void setType(const char *);

    char *getType() const { return type; }

    void details() const override;
    ostream &format(ostream &) const override;

    ~Motorcycle();

private:
    char *type;
};

#endif