#pragma once
#include "priQueue.h"


template <class T>
class Early_priQueue : public priQueue <T>
{
public:
	bool Reschedule2( T& P)
	{
		srand(time(NULL));
		int index = rand() % count;  // random number from 0 to count
		Node<T>* ptr = head;
		index--;
		while (index >= 0)
		{
			ptr = ptr->getNext();
			index--;
		}
		count--; //

		P = ptr->getItem();

		if (ptr == head)
		{
			head = this->head->getNext();
			delete ptr;
			ptr = NULL;
		}
		else
		{
			Node <T>* prev = this->head;
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
