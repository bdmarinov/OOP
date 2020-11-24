#ifndef PAIR_H
#define PAIR_H

#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
class Pair
{
public:
    Pair();
    Pair(const char *, T);
    Pair(const Pair &);
    Pair &operator=(const Pair &);

    char* getKey() const { return key; }
    T getValue() const { return value; }

    void print() const;

    void setValue(T);

    ~Pair();

private:
    T value;
    char *key;
    void setKey(const char *);
};

template <typename T>
Pair<T>::Pair()
{
    key = nullptr;
}

template <typename T>
Pair<T>::Pair(const char *n_key, T n_value) : value(n_value)
{
    key = nullptr;
    setKey(n_key);
}

template <typename T>
Pair<T>::Pair(const Pair<T> &pair) : value(pair.value)
{
    key = nullptr;
    setKey(pair.key);
}

template <typename T>
Pair<T> &Pair<T>::operator=(const Pair<T> &pair)
{
    if (this != &pair)
    {
        setKey(pair.key);
        setValue(pair.value);
    }
    return *this;
}

template <typename T>
void Pair<T>::print() const
{
    cout << "Key: " << key << "; Value: " << value << "\n";
}

template <typename T>
void Pair<T>::setValue(T n_value)
{
    value = n_value;
}

template <typename T>
void Pair<T>::setKey(const char *n_key)
{
    if (key != nullptr)
    {
        delete[] key;
        key = nullptr;
    }
    key = new char[strlen(n_key) + 1];
    strcpy(key, n_key);
}

template <typename T>
Pair<T>::~Pair()
{
    delete[] key;
}

#endif