#include "Motorcycle.h"

Motorcycle::Motorcycle() : Vehicle(), type(nullptr)
{

}

Motorcycle::Motorcycle(const char *n_make, const char *n_model, const char *n_color, int n_year,
 int n_mileage, const char* n_type) : Vehicle(n_make, n_model, n_color, n_year, n_mileage)
{
    type = nullptr;
    setType(n_type);
}

Motorcycle::Motorcycle(const Motorcycle & motorcycle) : Vehicle(motorcycle)
{
    type = nullptr;
    setType(motorcycle.type);
}

Motorcycle & Motorcycle::operator=(const Motorcycle & motorcycle)
{
    if(this != & motorcycle)
    {
        Vehicle::operator=(motorcycle);
        setType(motorcycle.type);
    }
    return *this;
}

void Motorcycle::setType(const char * n_type)
{
    if(type != nullptr)
    {
        delete[] type;
        type = nullptr;
    }
    type = new char[strlen(n_type) + 1];
    strcpy(type, n_type);
}

void Motorcycle::details() const
{
    cout << "Motorcycle details: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << " "  << getType() << "\n";
}

ostream & Motorcycle::format(ostream & out) const
{
    out << "Motorcycle: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << " "  << getType() << "\n";
    return out;
}

Motorcycle::~Motorcycle()
{
    delete[] type;
}