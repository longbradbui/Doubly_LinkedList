#include "list.h"
#include <iostream>
using namespace std;

int main()
{
    List<int> l1;
    int a1 = 1;
    int a2 = 2;
    int a3 = 3;
    int a4 = 4;
    int a5 = 5;
    int a6 = 6;
    int a7 = 7;
    int a8 = 8;
    int a9 = 9;
    l1.InsertNewItem(&a9);
    l1.InsertNewItem(&a2);
    l1.InsertNewItem(&a7);
    l1.InsertNewItem(&a8);
    l1.InsertNewItem(&a1);
    l1.InsertNewItem(&a9);
    l1.InsertNewItem(&a6);
    l1.InsertNewItem(&a3);
    l1.InsertNewItem(&a2);
    l1.InsertNewItem(&a5);
    l1.InsertNewItem(&a7);
    l1.InsertNewItem(&a5);
    l1.InsertNewItem(&a4);
    l1.InsertNewItem(&a6);
    l1.InsertNewItem(&a5);
    l1.InsertNewItem(&a7);
    l1.InsertNewItem(&a1);
    cout << l1;
    cout << l1.RemoveAll(a7) << " duplicates of #" << a7 << " has been removed.";
    cout << endl << l1;
    l1.ReverseList();
    cout << l1;
    cout << endl << l1.head << " || " << l1.tail << endl;
}


