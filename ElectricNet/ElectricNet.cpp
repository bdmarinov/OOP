#include "ElectricNet.h"

ElectricNet::ElectricNet(int n_consumption) : currentConsumption(0)
{
    setMaxConsumption(n_consumption);

    size = 0;
    capacity = 4;
    devices = new ElectricDevice[capacity];
}

ElectricNet::ElectricNet(const ElectricNet &en) : currentConsumption(en.currentConsumption),
                                                  maxConsumption(en.maxConsumption)
{
    size = en.size;
    capacity = en.capacity;

    devices = new ElectricDevice[capacity];

    for (int i = 0; i < size; i++)
    {
        devices[i] = en.devices[i];
    }
}

ElectricNet &ElectricNet::operator=(const ElectricNet &en)
{
    if (this != &en)
    {
        if (devices != nullptr)
        {
            delete[] devices;
            devices = nullptr;
        }

        currentConsumption = en.currentConsumption;
        setMaxConsumption(en.maxConsumption);
        size = en.size;
        capacity = en.capacity;

        devices = new ElectricDevice[capacity];

        for (int i = 0; i < size; i++)
        {
            devices[i] = en.devices[i];
        }
    }
    return *this;
}

/*
//ElectricNet reference + and += operators (but in this case not needed to be references)
ElectricNet &ElectricNet::operator+(const ElectricDevice &ed)
{
    if (currentConsumption + ed.getPower() <= maxConsumption)
    {
        if (full())
        {
            resize();
        }
        devices[size++] = ed;
        currentConsumption += ed.getPower();
    }
    return *this;
}

ElectricNet &ElectricNet::operator+=(const ElectricDevice &ed)
{
    if (currentConsumption + ed.getPower() <= maxConsumption)
    {
        if (full())
        {
            resize();
        }
        devices[size++] = ed;
        currentConsumption += ed.getPower();
    }
    return *this;
}
*/

//No need to return reference - the task doesn't require it, so + and += are void in this case
void ElectricNet::operator+(const ElectricDevice &ed)
{
    if (currentConsumption + ed.getPower() <= maxConsumption)
    {
        if (full())
        {
            resize();
        }
        devices[size++] = ed;
        currentConsumption += ed.getPower();
    }
}

void ElectricNet::operator+=(const ElectricDevice &ed)
{
    if (currentConsumption + ed.getPower() <= maxConsumption)
    {
        if (full())
        {
            resize();
        }
        devices[size++] = ed;
        currentConsumption += ed.getPower();
    }
}

void ElectricNet::operator-(const ElectricDevice &ed)
{
    if (!empty())
    {
        for (int i = 0; i < size; i++)
        {
            if (devices[i] == ed)
            {
                for (int j = i; j < size - 1; j++)
                {
                    devices[j] = devices[j + 1];
                }
                currentConsumption -= ed.getPower();
                size--;
                return;
            }
        }
    }
}

void ElectricNet::operator-=(const ElectricDevice &ed)
{
    if (!empty())
    {
        for (int i = 0; i < size; i++)
        {
            if (devices[i] == ed)
            {
                for (int j = i; j < size - 1; j++)
                {
                    devices[j] = devices[j + 1];
                }
                currentConsumption -= ed.getPower();
                size--;
                return;
            }
        }
    }
}

ElectricDevice &ElectricNet::operator[](const char *n_name)
{
    for (int i = 0; i < size; i++)
    {
        if (isEqual(devices[i].getName(), n_name))
        {
            return devices[i];
        }
    }
}

bool ElectricNet::operator!()
{
    return empty();
}

void ElectricNet::print() const
{
    cout << "Electric Net information:\n";
    cout << "Number of devices: " << size << "\n";

    for (int i = 0; i < size; i++)
    {
        cout << devices[i];
    }
    cout << "\n";
}

void ElectricNet::resize()
{
    ElectricDevice *helper = devices;

    devices = new ElectricDevice[capacity * 2];

    for (int i = 0; i < size; i++)
    {
        devices[i] = helper[i];
    }

    capacity *= 2;

    delete[] helper;
}

void ElectricNet::setMaxConsumption(int n_consumption)
{
    (n_consumption >= 0) ? maxConsumption = n_consumption : maxConsumption = 0;
}

bool ElectricNet::empty() const
{
    return size == 0;
}

bool ElectricNet::full() const
{
    return size == capacity;
}

ElectricNet::~ElectricNet()
{
    delete[] devices;
}