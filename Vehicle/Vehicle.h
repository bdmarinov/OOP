#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string.h>

using namespace std;

class Vehicle
{
public:
    Vehicle();
    Vehicle(const char *, const char *, const char *, int, int);
    Vehicle(const Vehicle &);
    Vehicle &operator=(const Vehicle &);

    void setMake(const char *);
    void setModel(const char *);
    void setColor(const char *);
    void setYear(int);
    void setMileage(int);

    char *getMake() const { return make; }
    char *getModel() const { return model; }
    char *getColor() const { return color; }
    int getYear() const { return year; }
    int getMileage() const { return mileage; }

    friend ostream &operator<<(ostream &, const Vehicle &);
    friend istream &operator>>(istream &, Vehicle &);

    virtual void details() const = 0;
    virtual ostream &format(ostream &) const;
    virtual istream &write(istream &);

        virtual ~Vehicle();

private:
    char *make;
    char *model;
    char *color;
    int year;
    int mileage;

    void nulify();
    void erase();
};

#endif