#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    List<int> l1;
    int a1 = 10;
    int a2 = 9;
    int a3 = 10;
    int a4 = 9;
    int a5 = 11;
    l1.InsertNewItem(&a5);
    l1.InsertNewItem(&a1);
    l1.InsertNewItem(&a2);
    l1.InsertNewItem(&a3);
    l1.InsertNewItem(&a4);
    cout << l1;
    cout << "\n" << l1.head << " || " << l1.tail << endl;
}

