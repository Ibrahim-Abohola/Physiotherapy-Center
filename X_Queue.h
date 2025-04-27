#pragma once
#include "EU_Queue.h"


template <class T>
class X_Queue : public EU_Queue <T>
{
public:

	X_Queue() : EU_Queue<T>()
	{

	}

	bool Cancel(T& P)
	{
		if (this->isEmpty())
			return false;
		int index = rand() % this->count;  // random number from 0 to count
		Node<T>* ptr = this->frontPtr;
		index--;
		while (index >= 0)
		{
			ptr = ptr->getNext();
			index--;
		}
		T item = ptr->getItem();
		if (~(*item))
		{
			this->count--;
			P = item;
			if (ptr == this->frontPtr)
			{
				this->frontPtr = this->frontPtr->getNext();
				delete ptr;
				ptr = NULL;
			}

			else if (ptr == this->backPtr)
			{

				Node <T>* prev = this->frontPtr;
				while (prev->getNext()->getNext())
				{
					prev = prev->getNext();
				}
				delete ptr;
				prev->setNext(NULL);
				this->backPtr = prev;
			}
			else
			{

				Node <T>* prev = this->frontPtr;
				while (prev && prev->getNext() != ptr)
				{
					prev = prev->getNext();
				}
				if (prev)
				{
					prev->setNext(ptr->getNext());
					delete ptr;
					ptr = NULL;
				}
			}
			return true;
		}

		return false;

	}



};