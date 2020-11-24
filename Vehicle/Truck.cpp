#include "Truck.h"

Truck::Truck() : Vehicle(), size(0)
{
}

Truck::Truck(const char *n_make, const char *n_model, const char *n_color, int n_year, int n_mileage,
             int n_size) : Vehicle(n_make, n_model, n_color, n_year, n_mileage)
{
    setSize(n_size);
}

Truck::Truck(const Truck &truck) : Vehicle(truck), size(truck.size)
{
}

Truck &Truck::operator=(const Truck &truck)
{
    if (this != &truck)
    {
        Vehicle::operator=(truck);
        setSize(truck.size);
    }
    return *this;
}

void Truck::setSize(int n_size)
{
    (n_size >= 0) ? size = n_size : size = 0;
}

void Truck::details() const
{
    cout << "Truck details: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << " " << getSize() << "\n";
}

ostream &Truck::format(ostream &out) const
{
    out << "Truck: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << " " << getSize() << "\n";
    return out;
}

Truck::~Truck()
{
}