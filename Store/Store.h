#ifndef STORE_H
#define STORE_H

#include "Product.h"
#include <fstream>

class Store
{

public:
    Store();
    Store(unsigned int);
    Store(const Store &);
    Store &operator=(const Store &);

    void add();
    void add(const Product &);

    void removeByID(unsigned int);
    void removeLast();

    void removeByBrand(const char *);
    void removeByModel(const char *);
    void removeByCategory(const char *);

    void updateByID(unsigned int);

    void print() const;

    void addToFile(ofstream &, const string);

    ~Store();

private:
    Product *products;
    int size, capacity;
    void resize();
    bool empty() const;
    bool full() const;
};

#endif