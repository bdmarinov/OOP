#include <iostream>
#include "Pair.h"
#include "Settings.h"

using namespace std;

int main()
{
    Pair<int> p1("Bogdan", 1);
    Settings<int> s;
    //p1.print();

    s.set("Bogdan", 10);

    int value;
    s.get("Bogdan", value);

    //cout << value << "\n";
    s.set("Pesho", 11);
    s.set("Ivan", 20);
    s.set("Tosho", 25);
    s.set("Iveta", 100);


    s.print();

    Settings<int> ss(s);
    //ss = s;
    ss.print();
    ss.set("Iveta", 1000);

    ss.print();
    s.print();
    s.set("Tanchev", 800);
    ss.print();
    s.print();

    return 0;
}