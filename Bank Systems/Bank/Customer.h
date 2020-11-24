#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer
{
public:
	Customer(int, string ,string);
	
	int getID() const;
	string getName() const;
	string getAddress() const;
	
	void display() const;

	~Customer();

private:
	int id;
	string name;
	string address;
};

