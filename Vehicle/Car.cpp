#include "Car.h"

Car::Car() : Vehicle()
{
}

Car::Car(const char *n_make, const char *n_model, const char *n_color, int n_year, int n_mileage)
    : Vehicle(n_make, n_model, n_color, n_year, n_mileage)
{
}

Car::Car(const Car &car) : Vehicle(car)
{
}

Car &Car::operator=(const Car &car)
{
    if (this != &car)
    {
        Vehicle::operator=(car);
    }
    return *this;
}

void Car::details() const
{
    cout << "Car details: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << "\n";
}

/*ostream &operator<<(ostream & out, const Car & car)
{
    out << "Car: ";
    out << static_cast<const Vehicle &>(car);
    return out;
}*/

ostream &Car::format(ostream &out) const
{
    out << "Car: " << getMake() << " " << getModel() << " " << getColor() << " " << getYear() << " " << getMileage() << "\n";
    return Vehicle::format(out);
}

istream &Car::write(istream & in)
{
    char n_make[256];
    in.getline(n_make, 256);
    setMake(n_make);

    char n_model[256];
    in.getline(n_model, 256);
    setModel(n_model);

    char n_color[256];
    in.getline(n_color, 256);
    setColor(n_color);

    int n_year, n_mileage;
    in >> n_year;
    in.ignore();
    setYear(n_year);
    
    in >> n_mileage;
    in.ignore();
    setMileage(n_mileage);

    return Vehicle::write(in);
}


Car::~Car()
{
}