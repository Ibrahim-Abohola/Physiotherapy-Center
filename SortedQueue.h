#pragma once
#include "LinkedQueue.h"


template <class T>
class SortedQueue : public LinkedQueue<T>
{
public:
	SortedQueue() : LinkedQueue<T>()
	{
	}
	bool InsertSorted(T data) {
		this->count++;
		if (this->frontPtr) {
			if (data <= this->frontPtr->getItem()) {
				Node<T>* newNode = new Node<T>(data);
				newNode->setNext(this->frontPtr);
				this->frontPtr = newNode;
				return true;
			}	
			bool inserted = true;
			Node<T>* ptr = this->frontPtr->getNext();
			Node<T>* prev = this->frontPtr;
			while (ptr) {
				if (prev->getItem() <= data && ptr->getItem() >= data) {
					Node<T>* newNode = new Node<T>(data);
					newNode->setNext(ptr);
					prev->setNext(newNode);
					return true;
				}
				prev = ptr;
				ptr = ptr->getNext();
			}
			if (data >= prev->getItem()) {
				Node<T>* newNode = new Node<T>(data);
				newNode->setNext(NULL);
				prev->setNext(newNode);
				return true;
			}
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			newNode->setNext(NULL);
			this->frontPtr = newNode;
			return true;
		}
		return false;
	}
};



