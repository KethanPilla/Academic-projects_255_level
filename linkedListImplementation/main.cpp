#include <iostream>
#include "linkedList.h"
using namespace std;

int main()
{																		// deep copy & shallow copy
    linkedListType myLL;

    int number;

    cout << "List 8: Enter 8 integers: ";

    for (int count = 0; count < 8; count++)
    {
        cin >> number;
        myLL.insert(number);
    }

    cout << endl;
    cout << "Line 16: intList: ";
    myLL.print();
    cout << endl;

    cout << "Line 18: Enter the number to be "
         << "deleted: ";
    cin >> number;
    cout << endl;

    myLL.deleteNode(number);

    cout << "Line 22: After removing " << number
         << " intList: ";
    myLL.print();
    cout << endl;

    cout << "Line 25: Enter the search item: ";

    cin >> number;
    cout << endl;

    if (myLL.search(number))
        cout << "Line 29: " << number
             << " found in intList." << endl;
    else
        cout << "Line 31: " << number
             << " is not in intList." << endl;


    return 0;
}
