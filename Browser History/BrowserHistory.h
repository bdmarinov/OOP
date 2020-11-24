#ifndef BrowserHistory_H
#define BrowserHistory_H

#include "HistoryEntry.h"

class BrowserHistory
{
public:
    BrowserHistory() = delete;
    BrowserHistory(int );
    BrowserHistory(const BrowserHistory &);
    BrowserHistory & operator=(const BrowserHistory &);

    void add();
    void add(const HistoryEntry &);
    void printHistory() const;
    int historyByMonth(int ) const;
    int maxMonth() const;
    void removeLast();
    BrowserHistory concat(const BrowserHistory &, const BrowserHistory &);

    ~BrowserHistory();

private:
    int N, current;
    HistoryEntry * history;
    bool empty() const;
    bool full() const;
    void setHistory(const HistoryEntry *, int);
    HistoryEntry & mergeHistory(const HistoryEntry *, const HistoryEntry *, int, int);
};

#endif