// doubly LinkedList Question

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int songID;
    string songName;
    float duration;
    Node *prev;
    Node *next;
};

class LL
{
protected:
    Node *head;
    Node *tail;
    Node *current;

public:
    LL()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }
    virtual void insertAtTail(const int &id, const string &n, const float &d) = 0;
    virtual bool deleteByName(const string &name) = 0;
    virtual Node *playNext() = 0;
    virtual Node *playPrev() = 0;
    virtual bool isEmpty() = 0;
    virtual void display() = 0;
    virtual Node *highestRating() = 0;
    virtual void reverseLL() = 0;
    ~LL()
    {
        delete head;
        delete tail;
    }
};

class myLL : public LL
{
public:
    void insertAtTail(const int &id, const string &n, const float &d);
    bool deleteByName(const string &name);
    Node *playNext();
    Node *playPrev();
    bool isEmpty();
    void display();
    Node *highestRating();
    void reverseLL();
};

bool myLL::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}

void myLL::insertAtTail(const int &id, const string &n, const float &d)
{
    Node *nn = new Node;
    nn->songID = id;
    nn->songName = n;
    nn->duration = d;
    nn->next = nullptr;
    nn->prev = nullptr;

    if (isEmpty())
    {
        head = nn;
        tail = nn;
        current = head;
    }
    else
    {
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }
}

void myLL::display()
{
    if (!isEmpty())
    {
        Node *t = head;
        while (true)
        {
            cout << t->songID << "  " << t->songName << "  " << t->duration << " " << endl;
            if (t->next == nullptr)
            {
                break;
            }
            t = t->next;
        }
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
    }
}

bool myLL::deleteByName(const string &name)
{
    if (isEmpty())
    {
        cout << "Element not removed because Linked list is Empty" << endl;
        return false;
    }
    else
    {
        Node *t = head;
        while (true)
        {
            if (t->songName == name)
            {
                if (t->prev == nullptr)
                {
                    head = t->next;
                    head->prev = nullptr;
                    delete t;
                }

                if (t->next == nullptr)
                {
                    tail = t->prev;
                    tail->next = nullptr;
                    delete t;
                }
                else if (t->prev != nullptr && t->next != nullptr)
                {
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    delete t;
                }

                return true;
            }

            else if (t->next == nullptr)
            {
                break;
            }

            t = t->next;
        }
        cout << "Movie not found" << endl;
        return false;
    }
}

Node *myLL::playNext()
{
    if (current->next != nullptr)
    {
        current = current->next;
        return current;
    }
    else
    {
        cout << "LinkedList ended or current is last node" << endl;
        return current;
    }
}

Node *myLL::playPrev()
{
    if (current->prev != nullptr)
    {
        current = current->prev;
        return current;
    }
    else
    {
        cout << "LinkedList ended or current is first node" << endl;
        return current;
    }
}

Node *myLL::highestRating()
{
    if (!isEmpty())
    {
        Node *t = head;
        Node *hn = t;
        while (true)
        {
            if (t->next == nullptr)
            {
                break;
            }
            if (hn->duration < t->duration)
            {
                hn = t;
            }
            t = t->next;
        }
        return hn;
    }
    else
    {
        cout << "LinkedList is Empty" << endl;
        return nullptr;
    }
}

void myLL::reverseLL()
{
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    myLL obj;
    obj.insertAtTail(1, "naat", 4.5);
    obj.insertAtTail(2, "naat1", 4.2);
    obj.insertAtTail(3, "naat2", 5);
    obj.insertAtTail(4, "naat3", 3.5);

    obj.display();
    cout << endl;

    obj.playNext();
    obj.playNext();
    obj.playNext();
    Node *n = obj.playNext();
    cout << n->songID << "  " << n->songName << "  " << n->duration << endl;

    obj.playPrev();
    obj.playPrev();
    obj.playPrev();
    n = obj.playPrev();
    cout << n->songID << "  " << n->songName << "  " << n->duration << endl;

    Node *hn = obj.highestRating();
    cout << hn->songID << "  " << hn->songName << "  " << hn->duration << endl;

    obj.reverseLL();
    cout<<endl;

    obj.display();

    obj.deleteByName("naat2");
    cout<<endl;
    obj.display();
}