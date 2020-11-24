#include "stdafx.h"
#include "Block.h"


Block::Block() : apartments(0)
{
	address = nullptr;
}

Block::Block(const Block & other) : Building(other), apartments(other.apartments)
{
	setAddress(other.getAddress());
}

Block & Block::operator =(const Block & other)
{
	if (this != &other) {
		Building::operator=(other);
		apartments = other.apartments;
		setAddress(other.getAddress());
	}
	return *this;
}

void Block::setApartments(unsigned int n_apartments)
{
	apartments = n_apartments;
}

void Block::setAddress(const char * n_address)
{
	if (address != nullptr) {
		delete[] address;
		address = nullptr;
	}
	address = new char[strlen(n_address) + 1];
	strcpy(address, n_address);
}

unsigned int Block::getApartments() const
{
	return apartments;
}

char * Block::getAddress() const
{
	return address;
}

bool Block::operator <(const Block & block) const
{
	return(apartments < block.apartments);
}

Block::~Block()
{
	delete[] address;
}
