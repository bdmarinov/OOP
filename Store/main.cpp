#include <iostream>
#include "Product.h"
#include "Store.h"
#include <fstream>
#include <string>
#include <ostream>

void clear()
{
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

using namespace std;

int main()
{
    Store store;

    Product p1("Nike", "Air Max", "Shoes", 180, 11);
    Product p2("Nike", "Air Max", "Shoes", 240, 7);
    Product p3("Adidas", "Sport+", "Shoes", 200, 3);
    Product p4("Nike", "Jordan", "Shoes", 330, 2);
    Product p5("Adidas", "Sport", "Shoes", 150, 5);

    //ofstream myfile;
    /*myfile.open("example.txt");

    myfile << p1 << "\n";
    myfile << p2 << "\n";
    myfile << p3 << "\n";
    myfile << p4 << "\n";
    myfile << p5 << "\n";

    myfile.close();*/

    store.add(p1);
    store.add(p2);
    store.add(p3);
    store.add(p4);
    store.add(p5);

    //store.print();

    //cout << "\n\n";
    //int id;
    //cin>>id;
    //store.removeByID(id);
    //store.removeLast();
    //store.updateByID(8);

    //store.removeByBrand("Adidas");
    //store.removeByModel("Air Max");
    //store.removeByCategory("Shoes");

    store.print();
    //store.addToFile(myfile, "store.txt");

    int working = 0, errorCount = 0;

    while (working == 0)
    {
        cout << "Choose number from one of the following store operations:\n";
        cout << "1. Add new product\n";
        cout << "2. Remove a product\n";
        cout << "3. Print store information\n";
        cout << "4. Export store information to a file\n";
        cout << "5. Exit store\n";

        int value;
        cin >> value;
        cin.ignore();

        switch (value)
        {
        case 1:
            errorCount = 0;
            clear();
            store.add();
            break;
        case 2:
        {
            errorCount = 0;
            clear();
            cout << "Choose number from one of the following ways to remove a product:\n";
            cout << "1. Delete by id\n";
            cout << "2. Delete by brand\n";
            cout << "3. Delete by model\n";
            cout << "4. Delete by category\n";

            int removal = 0;
            cin >> removal;
            cin.ignore();

            switch (removal)
            {
            case 1:
                clear();
                store.print();
                int id;
                cout << "Please choose a valid id of the product you want to remove: ";
                cin >> id;
                cin.ignore();
                cout << "\n";
                store.removeByID(id);
                break;

            case 2:
                clear();
                store.print();
                char n_brand[256];
                cout << "Please choose a valid brand of the product you want to remove: ";
                cin.getline(n_brand, 256);
                cout << "\n";
                store.removeByBrand(n_brand);
                break;

            case 3:
                clear();
                store.print();
                char n_model[256];
                cout << "Please choose a valid model of the product you want to remove: ";
                cin.getline(n_model, 256);
                cout << "\n";
                store.removeByModel(n_model);
                break;

            case 4:
                clear();
                store.print();
                char n_category[256];
                cout << "Please choose a valid category of the product you want to remove: ";
                cin.getline(n_category, 256);
                cout << "\n";
                store.removeByCategory(n_category);
                break;
            default:
                break;
            }
            break;
        }
        case 3:
            errorCount = 0;
            clear();
            store.print();
            break;
        case 4:
        {
            errorCount = 0;
            clear();
            cout << "Please enter valid filename in which you want the store to be exported to: \n";
            string filename;
            getline(cin, filename);

            ofstream file;
            store.addToFile(file, filename);
        }
        case 5:
            clear();
            cout << "Exiting store.\n";
            working = -1;
            break;
        default:
            clear();
            errorCount++;
            cout << "Please enter valid key." << (3 - errorCount) << " more attempts remaining!\n";
            if (errorCount == 3)
            {
                working = -1;
            }
            break;
        }
    }

    return 0;
}