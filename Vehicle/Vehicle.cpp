#include "Vehicle.h"

Vehicle::Vehicle() : year(0), mileage(0)
{
    nulify();
}

Vehicle::Vehicle(const char *n_make, const char *n_model, const char *n_color, int n_year, int n_mileage)
{
    nulify();

    setMake(n_make);
    setModel(n_model);
    setColor(n_color);
    setYear(n_year);
    setMileage(n_mileage);
}

Vehicle::Vehicle(const Vehicle &vehicle) : year(vehicle.year), mileage(vehicle.mileage)
{
    nulify();

    setMake(vehicle.make);
    setModel(vehicle.model);
    setColor(vehicle.color);
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle)
{
    if (this != &vehicle)
    {
        setMake(vehicle.make);
        setModel(vehicle.model);
        setColor(vehicle.color);
        setYear(vehicle.year);
        setMileage(vehicle.mileage);
    }
    return *this;
}

void Vehicle::setMake(const char *n_make)
{
    if (make != nullptr)
    {
        delete[] make;
        make = nullptr;
    }
    make = new char[strlen(n_make) + 1];
    strcpy(make, n_make);
}

void Vehicle::setModel(const char *n_model)
{
    if (model != nullptr)
    {
        delete[] model;
        model = nullptr;
    }
    model = new char[strlen(n_model) + 1];
    strcpy(model, n_model);
}

void Vehicle::setColor(const char *n_color)
{
    if (color != nullptr)
    {
        delete[] color;
        color = nullptr;
    }
    color = new char[strlen(n_color) + 1];
    strcpy(color, n_color);
}

void Vehicle::setYear(int n_year)
{
    (n_year >= 1950 && n_year <= 2021) ? year = n_year : year = 0;
}
void Vehicle::setMileage(int n_mileage)
{
    (n_mileage >= 0) ? mileage = n_mileage : mileage = 0;
}

void Vehicle::nulify()
{
    make = nullptr;
    model = nullptr;
    color = nullptr;
}

void Vehicle::erase()
{
    delete[] make;
    delete[] model;
    delete[] color;
}

/*ostream & operator<<(ostream & out, const Vehicle & vehicle)
{
    out << vehicle.make << " " << vehicle.model << " " << vehicle.color << " " << vehicle.year << " " << vehicle.mileage << "\n";
    return out; 
}*/

ostream & operator<<(ostream & out, const Vehicle & vehicle)
{
    return vehicle.format(out);
}

ostream &Vehicle::format(ostream &out) const
{
    return out;
}

istream & operator>>(istream & in, Vehicle & vehicle)
{
    return vehicle.write(in);
}

istream &Vehicle::write(istream & in)
{
    return in;
}

Vehicle::~Vehicle()
{
    erase();
}
