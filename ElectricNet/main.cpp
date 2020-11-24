#include <iostream>
#include "ElectricDevice.h"
#include "ElectricNet.h"

using namespace std;

int main()
{
    ElectricDevice ed[3];
    ElectricNet en(1000);

    for (int i = 0; i < 3; i++)
    {
        cin >> ed[i];
        en + ed[i];
    }

    for (int i = 0; i < 3; i++)
    {
        cout << ed[i];
    }

    cout << "\n";

    cout << en.getMaxConsumption() << "\n";
    en.print();

    //cout << en["ed3"] << "\n";

    cout << !en << "\n";

    ++en;
    --en;
    en++;
    en--;

    cout << en.getMaxConsumption() << " \n";

    return 0;
}