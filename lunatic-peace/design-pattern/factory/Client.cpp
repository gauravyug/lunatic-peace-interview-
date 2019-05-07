#include <iostream>
#include "ToyFactory.cpp"

using namespace std;

int main()
{
    int type;

    while (1) {
        cout << "Enter type or 0 to exit" << endl;
        cin >> type;
        if (!type) 
            break;
        Toy *t = ToyFactory::createToy(type);
        if (t) {
            t->showProducts();
            delete t;
        }
    }
    cout << "Exit.." << endl;
}