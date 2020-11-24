#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string.h>

using namespace std;

class Product
{

public:
    Product();
    Product(const char *, const char *, const char *, unsigned int, unsigned int);
    Product(const Product &);
    Product &operator=(const Product &);

    static unsigned int getSKU() { return SKU; }

    unsigned int getID() const { return id; }
    char *getBrand() const { return brand; }
    char *getModel() const { return model; }
    char *getCategory() const { return category; }
    unsigned int getPrice() const { return price; }
    unsigned int getCount() const { return count; }

    void setBrand(const char *);
    void setModel(const char *);
    void setCategory(const char *);
    void setPrice(unsigned int);
    void setCount(unsigned int);

    friend ostream &operator<<(ostream &, const Product &);
    friend istream &operator>>(istream &, Product &);

    ~Product();

private:
    static unsigned int SKU;
    unsigned int id;
    char *brand;
    char *model;
    char *category;
    unsigned int price;
    unsigned int count;

    void toNull();
};

#endif