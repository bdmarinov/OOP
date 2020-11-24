#include <iostream>
#include "HistoryEntry.h"
#include "BrowserHistory.h"

using namespace std;

int main()
{
    /*HistoryEntry hs;
    hs.printEntry();

    HistoryEntry h(30, "https://en.cppreference.com/w/c/string/byte/strcpy");

    h.printEntry();

    hs = h;
    hs.printEntry();

    hs.setUrl("https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/");
    hs.printEntry();
    h.printEntry();

    cout << "\n";

    cout << hs << "\n" << h <<"\n";

    HistoryEntry hue;
    cin >> hue;
    cout<<hue;*/

    BrowserHistory bh(6);

    for(int i = 0; i < 6; i++)
    {
        bh.add();
    }

    /*bh.printHistory();
    bh.add();
    HistoryEntry hs;
    HistoryEntry hs1;
    HistoryEntry hs2;
    HistoryEntry hs3;
    HistoryEntry hs4;

    bh.add(hs);
    bh.add(hs1);
    bh.add(hs2);
    bh.add(hs3);
    bh.add(hs4);


    bh.printHistory();

    BrowserHistory b(3);
    b = bh;

    cout<<"\n";

    b.removeLast();

    b.printHistory();
    cout<<"\n";*/

    bh.printHistory();

    return 0;
}