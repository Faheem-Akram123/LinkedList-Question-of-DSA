//Stack using LinkedList
/*if we use insertAtTail() , deleteFromTail() and isEmpty() functions
of LinkedList then it should be a Stack using LinkedList*/

//Queue using LinkedList
/*if we use insertAtTail() , deleteFromHead() and isEmpty() functions
of LinkedList then it should be a Queue using LinkedList*/

#include "../DSA-headerFiles-using-Cpp/myLL.h"

int main(){
    // myLL obj;

    // obj.insertAtTail(1);
    // obj.insertAtTail(2);
    // obj.insertAtTail(3);
    // obj.insertAtTail(4);
    // obj.insertAtTail(5);

    // obj.display();

    // obj.deleteFromTail();

    // cout<<endl;
    // obj.display();

    // obj.insertAtTail(5);

    // cout<<endl;
    // obj.display();

    myLL obj;
    obj.insertAtTail(1);
    obj.insertAtTail(2);
    obj.insertAtTail(3);
    obj.insertAtTail(4);
    obj.insertAtTail(5);

    obj.display();

    obj.deleteFromHead();
    cout<<endl;
    obj.display();


}