#include "HistoryEntry.h"

HistoryEntry::HistoryEntry() : month(1)
{
    url = new char[strlen("Empty URL") + 1];
    strcpy(url, "Emtpy URL");
}

HistoryEntry::HistoryEntry(int n_month, const char * n_url)
{
    setMonth(n_month);
    setUrl(n_url);
}

HistoryEntry::HistoryEntry(const HistoryEntry & hs)
{
    setMonth(hs.month);
    setUrl(hs.url);
}

HistoryEntry & HistoryEntry::operator=(const HistoryEntry & hs)
{
    if(this != & hs)
    {
        setMonth(hs.month);
        setUrl(hs.url);
    }
    return * this;
}

void HistoryEntry::setMonth(int n_month)
{
    (n_month > 0 && n_month < 13) ? month = n_month : month = 1; 
}

void HistoryEntry::setUrl(const char * n_url)
{
    if(url != nullptr)
    {
        delete[] url;
        url = nullptr;
    }
    url = new char[strlen(n_url) + 1];
    strcpy(url, n_url);
}

int HistoryEntry::getMonth() const
{
    return month;
}

char * HistoryEntry::getUrl() const
{
    return url;
}

void HistoryEntry::printEntry() const
{
    cout << "Month: " << month << "\n" << "Url: " << url << "\n";
}

HistoryEntry::~HistoryEntry()
{
    delete[] url;
}
