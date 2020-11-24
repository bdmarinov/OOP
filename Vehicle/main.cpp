#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

using namespace std;

int main()
{
    Vehicle *v[3];
    Car car("Tesla", "Model S", "Green", 2017, 10000);
    Truck truck("Scania", "1500X", "Black", 2010, 450000, 5);
    Motorcycle motorcycle("Yamaha", "CRX", "Blue", 2010, 18000, "Race");

    v[0] = &car;

    //v->details();

    v[1] = &truck;
    //v->details();

    v[2] = &motorcycle;
    //v->details();

    for (int i = 0; i < 3; i++)
    {
        v[i]->details();
        cout << *v[i];
    }
    cout << "\n";
    cout << car << "\n";
    cout << *v[0];

    cout << "\n\n";

    cin >> car;

    cout << car << "\n";

    return 0;
}