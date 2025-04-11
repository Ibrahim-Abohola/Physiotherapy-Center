#pragma once
#include "priNode.h"


//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
    int count;
public:
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    priQueue(const priQueue<T>& LQ) //ebra was here
    {
        frontPtr = backPtr = nullptr;
        priNode<T>* NodePtr = LQ.frontPtr;	//start at the front node in LQ
        while (NodePtr)
        {
            enqueue(NodePtr->getItem());	//get data of each node and enqueue it in this queue 
            NodePtr = NodePtr->getNext();
        }
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);
        count++;

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        count--;
        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    int GetCount() const {
        return count;
    }
    void PrintQueue(priQueue<T> Q)     //ebra was here
    {
        //For this function to work properly, the LikedQueue class MUST
        //have  a copy constructor (pass by value)
        T K;
        cout << "\nQueue contents: ";
        while (Q.dequeue(K))
            cout << K << " ";
        cout << endl;
    }

};
