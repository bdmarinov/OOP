#include "Product.h"

unsigned int Product::SKU = -1;

Product::Product()
{
    SKU++;
    id = SKU;

    brand = nullptr;
    model = nullptr;
    category = nullptr;

    price = 0;
    count = 0;
}

Product::Product(const char *n_brand, const char *n_model, const char *n_category,
                 unsigned int n_price, unsigned int n_count) : price(n_price), count(n_count)
{
    SKU++;
    id = SKU;

    toNull();
    setBrand(n_brand);
    setModel(n_model);
    setCategory(n_category);
}

Product::Product(const Product &p) : price(p.price), count(p.count)
{
    SKU++; //Product with same attributes, but it is still a new product, so new id is required
    id = SKU;

    toNull();
    setBrand(p.brand);
    setModel(p.model);
    setCategory(p.category);
}

Product &Product::operator=(const Product &p)
{
    if (this != &p)
    {
        SKU = p.SKU;
        id = p.id;
        price = p.price;
        count = p.count;

        setBrand(p.brand);
        setModel(p.model);
        setCategory(p.category);
    }
    return *this;
}

void Product::setBrand(const char * n_brand)
{
    if(brand != nullptr)
    {
        delete[] brand;
        brand = nullptr;
    }
    brand = new char[strlen(n_brand) + 1];
    strcpy(brand, n_brand);
}

void Product::setModel(const char * n_model)
{
    if(model != nullptr)
    {
        delete[] model;
        model = nullptr;
    }
    model = new char[strlen(n_model) + 1];
    strcpy(model, n_model);
}


void Product::setCategory(const char * n_category)
{
    if(category != nullptr)
    {
        delete[] category;
        category = nullptr;
    }
    category = new char[strlen(n_category) + 1];
    strcpy(category, n_category);
}

void Product::setPrice(unsigned int n_price)
{
    (n_price >= 0) ? price = n_price : price = 0;
}

void Product::setCount(unsigned int n_count)
{
    (n_count >= 0) ? count = n_count : count = 0;
}

ostream &operator<<(ostream & out, const Product & product)
{
    out << "Data of product with id: " << product.getID() << "\n";
    out << "Brand: " << product.getBrand() << "\n" << "Model: " << product.getModel() << "\n";
    out << "Category: " << product.getCategory() << "\n" << "Price: " << product.getPrice() << "\n";
    out << "Count: " << product.getCount() << "\n";

    return out; 
}

istream &operator>>(istream & in, Product & product)
{
    cout << "Please enter valid product data in the following order: \n";
    cout << "1. Brand; 2. Model, 3. Category, 4. Price, 5.Count \n";

    char n_brand[256], n_model[256], n_category[256];
    unsigned int n_price, n_count;

    in.getline(n_brand, 256);
    product.setBrand(n_brand);

    in.getline(n_model, 256);
    product.setModel(n_model);

    in.getline(n_category,256);
    product.setCategory(n_category);

    in >> n_price;
    product.setPrice(n_price);

    in.ignore();

    in >> n_count;
    product.setCount(n_count);

    in.ignore();

    return in;
}

void Product::toNull()
{
    brand = nullptr;
    model = nullptr;
    category = nullptr;
}

Product::~Product()
{
    delete[] brand;
    delete[] model;
    delete[] category;
}