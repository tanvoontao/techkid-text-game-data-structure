#pragma once

#include "DoublyLinkedNode.h"

template<class DataType>
class List
{
private:
	DoublyLinkedNode<DataType>* fTop;
	DoublyLinkedNode<DataType>* fLast;
	int fCount;

public: List();
	    ~List();
		bool isEmpty() const;
		int size() const;
		void find(const DataType& aElement);
		void push_front(const DataType& aElement);
		void push_back(const DataType& aElement);
		void pop_front(); 
		void pop_back(); 
		void remove(const DataType& aElement); 
		//void read(); 
		//void insert(const DataType& aElement);
		const DataType& operator[](int aIndex) const;
};

template<class DataType>
List<DataType>::List()
{
	fTop = &DoublyLinkedNode<DataType>::NIL;
	fLast = &DoublyLinkedNode<DataType>::NIL;
	fCount = 0;
}

template<class DataType>
List<DataType>::~List()
{
	if (!isEmpty())
	{
		while (fTop != &(DoublyLinkedNode<DataType>::NIL))
		{
			DoublyLinkedNode<DataType>* Temp = fTop;
			fTop = &fTop->getNxt();
			Temp->remove();
			fCount--;
		}
	}
}

template<class DataType>
bool List<DataType>::isEmpty() const
{
	if (fCount == 0)
		return true;
	else
		return false;
}

template<class DataType>
int List<DataType>::size() const
{
	return fCount;
}

template<class DataType>
void List<DataType>::find(const DataType& aElement)
{
	
}

template<class DataType>
void List<DataType>::push_front(const DataType& aElement)
{
	DoublyLinkedNode<DataType>* NewNode = new DoublyLinkedNode<DataType>(aElement);
	if (isEmpty())
	{
		fTop  = NewNode;
		fLast = NewNode;
	}
	else
	{
		DoublyLinkedNode<DataType>* Temp = fTop;
		fTop = NewNode;
		fTop->append(*Temp);
	}
	fCount++;
}

template<class DataType>
void List<DataType>::push_back(const DataType& aElement)
{
	DoublyLinkedNode<DataType>* NewNode = new DoublyLinkedNode<DataType>(aElement);
	if (isEmpty())
	{
		fTop  = NewNode;
		fLast = NewNode;
	}
	else
	{
		DoublyLinkedNode<DataType>* Temp = fLast;
		fLast = NewNode;
		fLast->prepend(*Temp);
	}
	fCount++;
}

template<class DataType>
void List<DataType>::pop_front()
{
	if (!isEmpty())
	{
		if (&fTop->getNxt() != &DoublyLinkedNode<DataType>::NIL)
		{
			DoublyLinkedNode<DataType>* Temp = fTop;
			fTop = &fTop->getNxt();
			Temp->remove();
		}
		else
		{
			fTop->remove();
		}
		fCount--;
	}
}

template<class DataType>
void List<DataType>::pop_back()
{
	if (!isEmpty())
	{
		if (&fLast->getPrev() != &DoublyLinkedNode<DataType>::NIL)
		{
			DoublyLinkedNode<DataType>* Temp = fLast;
			fLast = &fLast->getPrev();
			Temp->remove();
		}
		else
		{
			fLast->remove();
		}
		fCount--;
	}
}

template<class DataType>
void List<DataType>::remove(const DataType& aElement)
{
	DoublyLinkedNode<DataType>* Temp = fTop;
	

	if (!isEmpty())
	{
		for (int i = 0; i < fCount; i++)
		{
			if (Temp->getVal() == aElement)
			{
				if (&Temp->getNxt() == &(DoublyLinkedNode<DataType>::NIL)) // remove last node
				{
					pop_back();
					break;
				}
				if (&Temp->getPrev() == &(DoublyLinkedNode<DataType>::NIL))
				{
					pop_front();
					break;
				}

				Temp->remove();
				fCount--;
				break;
			}
			else
			{
				Temp = &Temp->getNxt();
			}
		}
	}
	
}

template<class DataType>
const DataType& List<DataType>::operator[](int aIndex) const
{
	if ((aIndex < fCount) && (aIndex >= 0))
	{
		DoublyLinkedNode<DataType>* Cursor = fTop;
		if (aIndex == 0)
		{
			return (Cursor->getVal());
		}
		for (int i = 0; i < aIndex; i++)
		{
			Cursor = &Cursor->getNxt();
		}
		/*while (aIndex != 0)
		{
			aIndex++;
			Cursor = &Cursor->getNxt();
		}*/
		return (Cursor->getVal());
	}
}