#ifndef HistoryEntry_H
#define HistoryEntry_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class HistoryEntry
{

public:
    HistoryEntry();
    HistoryEntry(int, const char *);
    HistoryEntry(const HistoryEntry &);
    HistoryEntry & operator =(const HistoryEntry &);

    void setMonth(int);
    void setUrl(const char *);

    int getMonth() const;
    char * getUrl() const;

    void printEntry() const;

    friend ostream & operator <<(ostream & out, const HistoryEntry & hs)
    {
        out << "Month: " << hs.month << "\n" << "Url: " << hs.url << "\n";
        return out;
    }

    friend istream & operator >>(istream & in, HistoryEntry & hs)
    {
        int n_month;
        cin >> n_month;
        cin.ignore();
        hs.setMonth(n_month);

        char n_url[256];
        in.getline(n_url,256);
        hs.setUrl(n_url);
        
        return in;
    }

    ~HistoryEntry();
private:
    int month;
    char * url;
};

#endif