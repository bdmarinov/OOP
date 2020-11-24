#include "stdafx.h"
#include "Building.h"


Building::Building() : area(0), floors(0)
{

}

Building::Building(unsigned int n_area, unsigned int n_floors) : area(n_area), floors(n_floors)
{

}

void Building::setArea(unsigned int n_area)
{
	area = n_area;
}

void Building::setFloors(unsigned int n_floors)
{
	floors = n_floors;
}

unsigned int Building::getArea() const
{
	return area;
}

unsigned int Building::getFloors() const
{
	return floors;
}

unsigned int Building::getTotalArea() const
{
	return area*floors;
}

unsigned int Building::getHeight() const
{
	return floors * 4;
}

bool Building::operator <(const Building & building) const
{
	return (getHeight() < building.getHeight());
}

Building::~Building()
{

}
