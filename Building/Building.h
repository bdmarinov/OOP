#pragma once
#include <iostream>

using namespace std;

class Building
{
public:
	Building();
	Building(unsigned int, unsigned int);

	void setArea(unsigned int);
	void setFloors(unsigned int);

	unsigned int getArea() const;
	unsigned int getFloors() const;

	unsigned int getTotalArea() const;
	unsigned int getHeight() const;

	bool operator <(const Building &) const;

	friend ostream & operator <<(ostream & out, const Building & obj)
	{
		out << "Building: " << obj.area << " " << obj.floors << "\n";
		return out;
	}

	~Building();

private:
	unsigned int area;
	unsigned int floors;
};

