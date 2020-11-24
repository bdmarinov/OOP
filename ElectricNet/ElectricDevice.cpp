#include "ElectricDevice.h"

bool isEqual(const char *a, const char *b)
{
    if (strlen(a) == strlen(b))
    {
        int len = strlen(a);
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

ElectricDevice::ElectricDevice() : power(0)
{
    name = nullptr;
    setName("Unknown name");
}

ElectricDevice::ElectricDevice(const char *n_name, int n_power)
{
    name = nullptr;
    setName(n_name);
    setPower(n_power);
}

ElectricDevice::ElectricDevice(const ElectricDevice &ed)
{
    name = nullptr;
    setName(ed.name);
    setPower(ed.power);
}

ElectricDevice &ElectricDevice::operator=(const ElectricDevice &ed)
{
    if (this != &ed)
    {
        setName(ed.name);
        setPower(ed.power);
    }
    return *this;
}

void ElectricDevice::setName(const char *n_name)
{
    if (name != nullptr)
    {
        delete[] name;
        name = nullptr;
    }
    name = new char[strlen(n_name) + 1];
    strcpy(name, n_name);
}

void ElectricDevice::setPower(int n_power)
{
    (n_power >= 0) ? power = n_power : power = 0;
}

bool ElectricDevice::operator==(const ElectricDevice &ed)
{
    return (power == ed.power && isEqual(name, ed.name));
}

ostream &operator<<(ostream &out, const ElectricDevice &ed)
{
    out << "Electric Device info:\n";
    out << "Name: " << ed.name << "; Power: " << ed.power << "\n";
    return out;
}

istream &operator>>(istream &in, ElectricDevice &ed)
{
    char n_name[256];
    in.getline(n_name, 256);

    ed.setName(n_name);

    int n_power;
    in >> n_power;
    in.ignore();
    ed.setPower(n_power);

    return in;
}

ElectricDevice::~ElectricDevice()
{
    delete[] name;
}
