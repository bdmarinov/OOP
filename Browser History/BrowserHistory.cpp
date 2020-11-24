#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(int n_N) : N(n_N)
{
    history = new HistoryEntry[N];
    current = 0;
}

BrowserHistory::BrowserHistory(const BrowserHistory & bh) : N(bh.N), current(bh.current)
{
    setHistory(bh.history, N);
}

void BrowserHistory::setHistory(const HistoryEntry * hs, int n)
{
    if(history != nullptr)
    {
        delete[] history;
        history = nullptr;
    }
    history = new HistoryEntry[n];
    for(int i = 0; i < n; i++)
    {
        history[i] = hs[i];
    }
}

BrowserHistory & BrowserHistory::operator=(const BrowserHistory & bh)
{
    if(this != & bh)
    {
        if(history != nullptr)
        {
            delete[] history;
            history = nullptr;
        }
        N = bh.N;
        current = bh.current;
        setHistory(bh.history, N);
    }
    return *this;
}

void BrowserHistory::add()
{
    if(!full())
    {
        HistoryEntry hs;
        cin >> hs;

        history[current++] = hs;
    }else
    {
        cout << "Browser History Limit Reached!\n";
    }
    
    
}

void BrowserHistory::add(const HistoryEntry & hs)
{
    if(!full())
    {
        history[current++] = hs;
    }else
    {
        cout << "Browser History Limit Reached!\n";
    }
}

void BrowserHistory::printHistory() const
{
    for(int i = 0; i < current; i++)
    {
        cout<<history[i];
    }
}

bool BrowserHistory::empty() const
{
    return current == 0;
}

bool BrowserHistory::full() const
{
    return current == N;
}

int BrowserHistory::historyByMonth(int month) const
{
    if(month > 0 && month < 13 && !empty())
    {
        int counter = 0;
        for(int i = 0; i < current; i++)
        {
            if(history[i].getMonth() == month)
            {
                counter++;
            }
        }
        return counter;
    }
    return 0;
}

int BrowserHistory::maxMonth() const
{
    int helper[13] = {0};
    for(int i = 0; i < current; i++)
    {
        int month = history[i].getMonth();
        helper[month]++;
    }

    int max = 0;
    int month = 1;
    for(int i = 1; i < 13; i++)
    {
        if(helper[i] > max)
        {
            month = i;
        }
    }
    return month;
}

void BrowserHistory::removeLast()
{
    if(!empty())
    {
        current--;
    }
}

HistoryEntry & BrowserHistory::mergeHistory(const HistoryEntry * hs1, const HistoryEntry * hs2, int n1, int n2)
{
    N = n1 + n2;
    HistoryEntry * hs = new HistoryEntry[N];

    for(int i = 0, j = 0; i < N; i++)
    {
        if(i < n1)
        {
            hs[i] = hs1[i];
        }else
        {
            hs[i] = hs2[j];
            j++;
        }
    }
    return *hs;
}

BrowserHistory BrowserHistory::concat(const BrowserHistory & bh1, const BrowserHistory & bh2)
{
    mergeHistory(bh1.history, bh2.history, bh1.N, bh2.N);
}

BrowserHistory::~BrowserHistory()
{
    delete[] history;
}
