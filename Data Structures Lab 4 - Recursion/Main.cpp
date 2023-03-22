#include <iostream>
#include "Stack.h"
#include "ItemType.h"
using namespace std;

int main()
{
    //pushes and pops the first stack to compare
    Stack s;
    ItemType item;
    item.SetItem(1);
    s.Push(item);
    item.SetItem(2);
    s.Push(item);
    item.SetItem(3);
    s.Push(item);
    item.SetItem(4);
    s.Push(item);
    item.SetItem(5);
    s.Push(item);
    cout<< "Original Stack: ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << endl;

    //pushes the same items as the origional, but now the list reverses. 
    item.SetItem(1);
    s.Push(item);
    item.SetItem(2);
    s.Push(item);
    item.SetItem(3);
    s.Push(item);
    item.SetItem(4);
    s.Push(item);
    item.SetItem(5);
    s.Push(item);
    s.Reverse();
    cout << "Reversed Stack: ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << " ";
    s.Pop().Print(cout);
    cout << endl;
    
    return 0;
}
