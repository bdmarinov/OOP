#pragma once
#include "Building.h"
class Block :
	public Building
{
public:
	Block();
	Block(const Block &);
	Block & operator =(const Block &);

	void setApartments(unsigned int);
	void setAddress(const char *);

	unsigned int getApartments() const;
	char * getAddress() const;

	bool operator <(const Block &) const;

	friend ostream & operator <<(ostream & out, const Block & obj)
	{
		if (obj.address) {
			out << "Block: " << obj.getArea() << " " << obj.getFloors() << " " << obj.apartments << " " << obj.address << "\n";
			return out;
		}
		out << "Block: " << obj.getArea() << " " << obj.getFloors() << " " << obj.apartments << " Unknown address" << "\n";
		return out;
	}

	~Block();

private:
	unsigned int apartments;
	char * address;
};

