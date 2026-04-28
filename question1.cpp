#include "../DSA-headerFiles-using-Cpp/myLL.h"

int main()
{
    myLL obj;
    cout << "before insert at position" << endl;
    obj.display();
    obj.insertAtPosition(333, 1);
    cout << "after insert at position" << endl;
    obj.display();
    obj.insertAtHead(120);
    obj.insertAtTail(200);
    cout << endl;
    obj.display();
    cout << endl;
    obj.insertAtPosition(5, 4);
    obj.display();
    obj.insertAtPosition(1, 3);
    cout << endl;
    obj.display();

    cout << endl;
    obj.insertAtPosition(1, 10);
    obj.insertAtPosition(1, 0);

    cout << "\nAfter deleting values : " << endl;
    cout << "delete value from head : " << obj.deleteFromHead() << endl;
    cout << "delete value from Tail : " << obj.deleteFromTail() << endl;

    obj.display();

    cout << "\n delete value from given position : " << obj.deleteFromPos(3) << endl;
    cout << "\n delete value from given position : " << obj.deleteFromPos(0) << endl;
    cout << "\n delete value from given position : " << obj.deleteFromPos(2) << endl;
    obj.display();

    cout << "\nSearch Value" << endl;
    cout << "Value is at position : " << obj.searchValue(333) << endl;
    cout << "Value is at position : " << obj.searchValue(20) << endl;


    obj.insertAtHead(100);
    obj.insertAtPosition(20,3);
    obj.insertAtTail(120);

    cout << "\nAfter update node's value" << endl;
    obj.updateNodeValue(80,3);
    obj.updateNodeValue(100,10);
    obj.display();
}