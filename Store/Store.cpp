#include "Store.h"

bool isEqual(const char *a, const char *b)
{
    if (strlen(a) == strlen(b))
    {
        int len = strlen(a);
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

Store::Store()
{
    size = 0;
    capacity = 4;

    products = new Product[capacity];
}

Store::Store(unsigned int N)
{
    size = 0;
    capacity = N;
    products = new Product[capacity];
}

Store::Store(const Store &s)
{
    size = s.size;
    capacity = s.capacity;

    products = new Product[capacity];
    for (int i = 0; i < size; i++)
    {
        products[i] = s.products[i];
    }
}

Store &Store::operator=(const Store &s)
{
    if (this != &s)
    {
        if (products != nullptr)
        {
            delete[] products;
            products = nullptr;
        }
        size = s.size;
        capacity = s.capacity;

        products = new Product[capacity];
        for (int i = 0; i < size; i++)
        {
            products[i] = s.products[i];
        }
    }
    return *this;
}

void Store::add()
{
    Product product;
    cin >> product;
    if (full())
    {
        resize();
    }
    products[size++] = product;
}

void Store::add(const Product &product)
{
    if (full())
    {
        resize();
    }
    products[size++] = product;
}

void Store::removeByID(unsigned int id)
{
    if (!empty())
    {
        for (int i = 0; i < size; i++)
        {
            if (products[i].getID() == id)
            {
                for (int j = i; j < size - 1; j++)
                {
                    products[j] = products[j + 1];
                }
                size--;
                return;
            }
        }
    }
}

void Store::removeLast()
{
    if (!empty())
    {
        size--;
    }
}

void Store::removeByBrand(const char *n_brand)
{
    if (!empty())
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (isEqual(products[i].getBrand(), n_brand))
            {
                counter++;
            }
        }

        //cout << "\ncounter: " << counter << "\n";

        if (counter != 0)
        {
            Product *helper = products;
            products = new Product[capacity];

            for (int i = 0, j = 0; i < size; i++)
            {
                if (!isEqual(helper[i].getBrand(), n_brand))
                {
                    products[j++] = helper[i];
                }
            }
            //cout << "\nsize: " << size << "\n";

            size = size - counter;

            delete[] helper;
        }
    }
}

void Store::removeByModel(const char *n_model)
{
    if (!empty())
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (isEqual(products[i].getModel(), n_model))
            {
                counter++;
            }
        }

        //cout << "\ncounter: " << counter << "\n";

        if (counter != 0)
        {
            Product *helper = products;
            products = new Product[capacity];

            for (int i = 0, j = 0; i < size; i++)
            {
                if (!isEqual(helper[i].getModel(), n_model))
                {
                    products[j++] = helper[i];
                }
            }
            //cout << "\nsize: " << size << "\n";

            size = size - counter;

            delete[] helper;
        }
    }
}

void Store::removeByCategory(const char *n_category)
{
    if (!empty())
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (isEqual(products[i].getCategory(), n_category))
            {
                counter++;
            }
        }

        //cout << "\ncounter: " << counter << "\n";

        if (counter != 0)
        {
            Product *helper = products;
            products = new Product[capacity];

            for (int i = 0, j = 0; i < size; i++)
            {
                if (!isEqual(helper[i].getCategory(), n_category))
                {
                    products[j++] = helper[i];
                }
            }
            //cout << "\nsize: " << size << "\n";

            size = size - counter;

            delete[] helper;
        }
    }
}

void Store::updateByID(unsigned int n_id)
{
    for (int i = 0; i < size; i++)
    {
        if (products[i].getID() == n_id)
        {
            cout << "Press one of the following keys in order to change the information of ";
            cout << "product with id: " << products[i].getID() << "\n";
            cout << "1. Brand; 2. Model; 3. Category; 4. Price; 5.Count \n";

            int value;
            cin >> value;
            cin.ignore();

            switch (value)
            {
            case 1:
                cout << "Enter new product brand: ";
                char n_brand[256];
                cin.getline(n_brand, 256);
                products[i].setBrand(n_brand);
                cout << "\n";
                break;
            case 2:
                cout << "Enter new product model: ";
                char n_model[256];
                cin.getline(n_model, 256);
                products[i].setModel(n_model);
                cout << "\n";
                break;
            case 3:
                cout << "Enter new product category: ";
                char n_category[256];
                cin.getline(n_category, 256);
                products[i].setCategory(n_category);
                cout << "\n";
                break;
            case 4:
                cout << "Enter new product price: ";
                unsigned int n_price;
                cin >> n_price;
                cin.ignore();
                products[i].setPrice(n_price);
                cout << "\n";
                break;
            case 5:
                cout << "Enter new product count: ";
                unsigned int n_count;
                cin >> n_count;
                cin.ignore();
                products[i].setCount(n_count);
                cout << "\n";
                break;
            default:
                break;
            }
            return;
        }
    }
}

void Store::print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << products[i];
    }
}

bool Store::empty() const
{
    return size == 0;
}

bool Store::full() const
{
    return size == capacity;
}

void Store::resize()
{
    Product *helper = products;

    products = new Product[capacity * 2];

    for (int i = 0; i < size; i++)
    {
        products[i] = helper[i];
    }

    capacity *= 2;

    delete[] helper;
}

void Store::addToFile(ofstream &file, const string filename)
{
    file.open(filename);
    for (int i = 0; i < size; i++)
    {
        file << products[i] << "\n";
    }
    file.close();
}

Store::~Store()
{
    delete[] products;
}