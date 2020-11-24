// Kontrolno2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Building.h"
#include "Block.h"

int main()
{
	/*
	Building one(150, 10);
	Building two(170, 11);

	cout << one << two;
	cout << (one < two) << "\n";
	one = two;
	cout << one;
	Building three = one;
	Building four(one);
	cout << three << four;
	*/

	Block first;
	Block second;

	first.setArea(150);
	first.setFloors(10);
	first.setApartments(50);
	first.setAddress("Stara Zagora, County Remiza, Rakovski 146 Street");

	second.setArea(170);
	second.setFloors(11);
	second.setApartments(51);
	second.setAddress("Stara Zagora, County Zagorka, 12-ti Pehoten Polk 16 Street");

	cout << first << second;
	cout << (first < second) << "\n";

	Block third, fourth;
	cout << (third < fourth) << "\n";

	third = second;
	fourth = first;

	cout << third << fourth;

	Block fifth(fourth);
	cout << fifth;

	second.setArea(210);
	second.setFloors(14);
	second.setApartments(78);
	second.setAddress("Sofia, County Studentski Grad, Georgi Bradistilov 1");
	cout << second;

	cout << (fifth < second) << "\n";


	fifth.setApartments(79);

	cout << (fifth < second) << "\n";

	cout << ((Building)fifth < (Building)second) << "\n";

	fifth.setFloors(14);

	cout << ((Building)fifth < (Building)second) << "\n";

	/*
	Block sixth;

	cout << sixth;

	sixth.setArea(99);
	sixth.setFloors(4);
	sixth.setApartments(16);

	cout << sixth;
	*/

	return 0;
}

