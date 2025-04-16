#pragma once
#include "priQueue.h"


template <class T>
class Early_priQueue : public priQueue <T>
{
public:
	bool Reschedule( T& P)
	{
	
		if (this->isEmpty())
			return false;

		int index = rand() % this->count;  // random number from 0 to count
		priNode<T>* ptr = this->head;
		index--;
		while (index >= 0)
		{
			ptr = ptr->getNext();
			index--;
		}
		this->count--;

		int pri;
		P = ptr->getItem(pri);

		if (ptr == this->head)
		{
			this->head = this->head->getNext();
			delete ptr;
			ptr = NULL;
		}
		else
		{
			priNode <T>* prev = this->head;
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


};