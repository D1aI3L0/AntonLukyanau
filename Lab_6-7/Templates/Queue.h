#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

#include "../Input.h"
#include "fstream"

using namespace std;

template<typename T>
struct queueList
{
    T data;
    queueList* next = NULL;
};

template<typename T>
struct queue
{
    queueList<T>* head = NULL;
    queueList<T>* tail = NULL;
};

template<typename T>
class Queue
{
    template<typename T1> friend ostream& operator <<(ostream&, const Queue<T1>&);
    template<typename T1> friend istream& operator >>(istream&, Queue<T1>&);


    template<typename T1> friend ifstream& operator >>(ifstream&, Queue<T1>&);
    template<typename T1> friend ofstream& operator <<(ofstream&, const Queue<T1>&);
    template<typename T1> friend fstream& operator >>(fstream&, Queue<T1>&);
    template<typename T1> friend fstream& operator <<(fstream&, const Queue<T1>&);
    queue<T> qe;
    int length = 0;
public:
    Queue();
    ~Queue();

    void FRead(fstream&);
    void FWrite(fstream&);

    T& Get(int);
    void Push(T);
    void Show();
    T& Remove();
    void Menu();
    Queue<T>& operator=(Queue<T>&);
    bool operator==(Queue<T>&);
    bool operator!=(Queue<T>&);
    bool operator>(Queue<T>&);
    bool operator<(Queue<T>&);
    bool operator>=(Queue<T>&);
    bool operator<=(Queue<T>&);
};


template<typename T>
istream& operator >>(istream& in, Queue<T> &queue)
{
    while(queue.qe.head)
        queue.Remove();

    int count;
    Input::Int(count, "How many elements you want to enter(1-10)?", 'b', 1, 10);

    for(int i = 0; i < count; i++)
    {
        T newElement;
        in >> newElement;
        queue.Push(newElement);
    }
    return in;
}


template<typename T>
ostream& operator <<(ostream& out, const Queue<T>& queue)
{
    queueList<T>* tmp = queue.qe.head;
    while(tmp)
    {
        out << tmp->data << endl;
        tmp = tmp->next;
    }
    return out;
}


template<typename T>
ifstream& operator >>(ifstream& fIn, Queue<T> &queue)
{
    while(queue.qe.head)
        queue.Remove();

    while(true)
    {
        T newElement;
        fIn >> newElement;
        if(fIn.eof())
            break;
        queue.Push(newElement);
    }
    return fIn;
}


template<typename T>
ofstream& operator <<(ofstream& fOut, const Queue<T>& queue)
{
    queueList<T>* tmp = queue.qe.head;
    while(tmp)
    {
        fOut << tmp->data << endl;
        tmp = tmp->next;
    }
    return fOut;
}


template<typename T>
fstream& operator >>(fstream& fIn, Queue<T> &queue)
{
    while(queue.qe.head)
        queue.Remove();

    while(true)
    {
        T newElement;
        fIn >> newElement;
        if(fIn.eof())
            break;
        queue.Push(newElement);
    }
    return fIn;
}


template<typename T>
fstream& operator <<(fstream& fOut, const Queue<T>& queue)
{
    queueList<T>* tmp = queue.qe.head;
    while(tmp)
    {
        fOut << tmp->data << endl;
        tmp = tmp->next;
    }
    return fOut;
}


template<typename T>
void Queue<T>::FRead(fstream &fIn)
{
    while(this->qe.head)
        Remove();

    while(!fIn.eof())
    {
        T newElement;
        fIn.read((char*)&newElement, sizeof(T));
        Push(newElement);
    }
}


template<typename T>
void Queue<T>::FWrite(fstream &fOut)
{
    queueList<T>* tmp = this->qe.head;
    while(tmp)
    {
        fOut.write((char*)&(tmp->data), sizeof(T));
        tmp = tmp->next;
    }
}


template<typename T>
Queue<T>::Queue() {}

template<typename T>
Queue<T>::~Queue()
{
    while(qe.head != NULL)
        Remove();
}


template<typename T>
T& Queue<T>::Get(int pos)
{
    queueList<T> *tmp = qe.head;
    for(int i = 0; i < pos-1; i++)
        tmp = tmp->next;
    return tmp->data;
}


template<typename T>
void Queue<T>::Push(T _data)
{
    queueList<T>* New = new queueList<T>;
    New->data = _data;
    if(qe.tail != NULL)
        qe.tail->next = New;
    else
        qe.head = New;
    qe.tail = New;
    length++;
}


template<typename T>
void Queue<T>::Show()
{
    if(!qe.head)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "\nQueue:\n";
    queueList<T>* list = qe.head;
    while(list != NULL)
    {
        cout << list->data << endl;
        list = list->next;
    }
}


template<typename T>
T& Queue<T>::Remove()
{
    T _data;
    queueList<T>* tmp = qe.head;
    qe.head = qe.head->next;
    _data = tmp->data;
    delete tmp;
    length--;
    if(!length)
        qe.tail = NULL;
    return _data;
}


template<typename T>
void Queue<T>::Menu()
{
    int rep;
    do
    {
        Show();
        int num;

        Input::Int(num, "\nWhat do you want to do?\n1. Add new element to queue\n2. Remove element from queue\n3. Show queue\n4. Get element by it position in queue\n",
                   'b', 1, 4);

        switch (num)
        {
            case 1:
            {
                T newData;
                cout << "\nEnter new data: ";
                cin >> newData;
                Push(newData);
                break;
            }

            case 2:
            {
                if(!this->length)
                {
                    cout << "Queue is empty\n";
                    break;
                }
                Remove();
                Show();
                break;
            }

            case 3:
            {
                Show();
                break;
            }

            case 4:
            {
                if(!this->length)
                {
                    cout << "\nQueue is empty\n";
                    break;
                }

                int pos;

                Input::Int(pos, "\nEnter position of element you want to get: ", 'b', 1, this->length);

                T res = Get(pos);
                cout << "\nSearched element:\n" << res;
                break;
            }

            default:
                break;
        }

        Input::Int(rep, "\nDo you want to do something else?\n1. Yes\n2. No\n", 'b', 1, 2);
    }while(rep == 1);
}


template<typename T>
Queue<T> &Queue<T>::operator=(Queue<T> &other)
{
    while(this->length)
        this->Remove();

    queueList<T>* temp = other.qe.head;
    while(temp)
    {
        this->Push(temp->data);
        temp = temp->next;
    }
    return *this;
}


template<typename T>
bool Queue<T>::operator==(Queue<T>& other)
{
    if (this->length != other.length)
        return false;

    if (!this->length && !other.length)
        return true;

    queueList<T> *first = this->qe.head;
    queueList<T> *second = other.qe.head;

    while(first)
    {
        if(first->data != second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    return true;
}


template<typename T>
bool Queue<T>::operator!=(Queue<T> &other)
{
    return !(*this == other);
}


template<typename T>
bool Queue<T>::operator>=(Queue<T> &other)
{
    if(!this->length && !other.length)
        return false;

    queueList<T> *first = this->qe.head;
    queueList<T> *second = other.qe.head;

    while(first && other)
    {
        if(first->data < second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    if(first && !second)
        return true;
    if(!first && second)
        return false;
    return true;
}


template<typename T>
bool Queue<T>::operator<=(Queue<T> &other)
{
    if(!this->length && !other.length)
        return false;

    queueList<T> *first = this->qe.head;
    queueList<T> *second = other.qe.head;

    while(first && other)
    {
        if(first->data > second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    if(!first && second)
        return true;
    if(first && !second)
        return false;
    return true;
}


template<typename T>
bool Queue<T>::operator<(Queue<T> &other)
{
    if(!this->length && !other.length)
        return false;

    queueList<T> *first = this->qe.head;
    queueList<T> *second = other.qe.head;

    while(first && other)
    {
        if(first->data >= second->data)
            return false;

        first = first->next;
        second = second->next;
    }

    if(!first && second)
        return true;
    if(first && !second)
        return false;
    return true;
}


template<typename T>
bool Queue<T>::operator>(Queue<T> &other)
{
    return !(*this <= other);
}

#endif //LAB5_QUEUE_H
