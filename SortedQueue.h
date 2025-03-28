#pragma once
#include "LinkedQueue.h"


template <class T>
class SortedQueue : public LinkedQueue
{
public:
	bool InsertSorted(T data) {
		if (Head) {
			if (data < Head->getItem()) {
				Node<T>* newnode = new Node<T>;
				newnode->setItem(data);
				newnode->setNext(Head);
				Head = newnode;
				return true;
			}
			Node<T>* ptr = Head;
			bool inserted = true;
			while (ptr) {
				if (ptr->getItem() == data) {
					return false;
				}
				ptr = ptr->getNext();
			}
			ptr = Head->getNext();
			Node<T>* prev = Head;
			while (ptr) {
				if (prev->getItem() < data && ptr->getItem() > data) {
					Node<T>* newnode = new Node<T>;
					newnode->setItem(data);
					newnode->setNext(ptr);
					prev->setNext(newnode);
					return true;
				}
				prev = ptr;
				ptr = ptr->getNext();
			}
			if (data > prev->getItem()) {
				Node<T>* newnode = new Node<T>;
				newnode->setItem(data);
				newnode->setNext(NULL);
				prev->setNext(newnode);
				return true;
			}
		}
		else
		{
			Node<T>* newnode = new Node<T>;
			newnode->setItem(data);
			newnode->setNext(NULL);
			Head = newnode;
			return true;
		}
		return false;
	}
};

