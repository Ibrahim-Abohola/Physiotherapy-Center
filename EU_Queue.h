#pragma once
#include "LinkedQueue.h"


template <class T>
class EU_Queue : public LinkedQueue<T>
{
public:
	EU_Queue() : LinkedQueue<T>()
	{
	}

	int CalcTreatmentLatency()
	{
		Node<T>* ptr = this->frontPtr;
		int TL = 0;
		while (ptr)
		{
			T item = ptr->getItem();
			TL += !item;
			ptr = ptr->getNext();
		}
		return TL;
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
				if (prev == this->backPtr)
					this->backPtr = newNode;
				return true;
			}
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			newNode->setNext(NULL);
			this->frontPtr = newNode;
			this->backPtr = newNode;
			return true;
		}
		return false;
	}
};

