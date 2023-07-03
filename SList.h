#pragma once
#include "SinglyLinkedNode.h"

template<class DataType>
class SList
{
private:
	SinglyLinkedNode<DataType>* fTop;
	SinglyLinkedNode<DataType>* fLast;
	int fCount;

public:
	SList();
	~SList();
	bool isEmpty() const;
	int size() const;
	void find(const DataType& aElement);
	void push_front(const DataType& aElement);
	//void push_back(const DataType& aElement);
	void pop_front();
	void pop_back();
	void remove(const DataType& aElement);
	//void read(); 
	//void insert(const DataType& aElement);
	const DataType& operator[](int aIndex) const;
};

template<class DataType>
SList<DataType>::SList()
{
	fTop = &SinglyLinkedNode<DataType>::NIL;
	fLast = &SinglyLinkedNode<DataType>::NIL;
	fCount = 0;
}

template<class DataType>
SList<DataType>::~SList()
{
	if (!isEmpty())
	{
		while (fTop != &(SinglyLinkedNode<DataType>::NIL))
		{
			SinglyLinkedNode<DataType>* Temp = fTop;
			fTop = &fTop->getNxt();
			Temp->remove();
			fCount--;
		}
	}
}

template<class DataType>
bool SList<DataType>::isEmpty() const
{
	if (fCount == 0)
		return true;
	else
		return false;
}

template<class DataType>
int SList<DataType>::size() const
{
	return fCount;
}

template<class DataType>
void SList<DataType>::find(const DataType& aElement)
{

}

template<class DataType>
void SList<DataType>::push_front(const DataType& aElement)
{
	SinglyLinkedNode<DataType>* NewNode = new SinglyLinkedNode<DataType>(aElement);
	if (isEmpty())
	{
		fTop = NewNode;
		fLast = NewNode;
	}
	else
	{
		SinglyLinkedNode<DataType>* Temp = NewNode;
		fTop->insertAtTheTop(*Temp);
		fTop = Temp;
	}
	fCount++;
}

template<class DataType>
void SList<DataType>::pop_front()
{
	if (!isEmpty())
	{
		if (&fTop->getNxt() != &SinglyLinkedNode<DataType>::NIL)
		{
			SinglyLinkedNode<DataType>* Temp = fTop;
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
void SList<DataType>::pop_back()
{
	if (!isEmpty())
	{
		SinglyLinkedNode<DataType>* tmpTop = fTop;
		SinglyLinkedNode<DataType>* nodeInFront = &(SinglyLinkedNode<DataType>::NIL);

		while (tmpTop != &(SinglyLinkedNode<DataType>::NIL))
		{
			if (&tmpTop->getNxt() == &(SinglyLinkedNode<DataType>::NIL))
			{
				nodeInFront->setNxt(&(SinglyLinkedNode<DataType>::NIL));
				tmpTop->remove();
				break;
			}
			nodeInFront = tmpTop;
			tmpTop = &tmpTop->getNxt();
		}
		//fTop = tmpTop;

		fCount--;
	}
}

template<class DataType>
void SList<DataType>::remove(const DataType& aElement)
{
	SinglyLinkedNode<DataType>* Temp = fTop;
	//int index = fCount - 1;

	SinglyLinkedNode<DataType>* theNodeInFront = &(SinglyLinkedNode<DataType>::NIL);


	if (!isEmpty())
	{
		for (int i = 0; i < fCount; i++)
		{
			if (Temp->getVal() == aElement)
			{
				// pop back got issue
				if (&Temp->getNxt() == &(SinglyLinkedNode<DataType>::NIL)) // remove last node
				{
					pop_back();
					break;
				}
				if (theNodeInFront == &(SinglyLinkedNode<DataType>::NIL))
				{
					//fTop = &Temp->getNxt();

					pop_front();
					break;
				}
				if ((&Temp->getNxt() != &(SinglyLinkedNode<DataType>::NIL)) &&
					(theNodeInFront != &(SinglyLinkedNode<DataType>::NIL)))
				{
					theNodeInFront->setNxt(&Temp->getNxt());
					Temp->remove();
					fCount--;
					break;
				}
			}
			else
			{
				theNodeInFront = Temp;
				Temp = &Temp->getNxt();
			}
		}
		
	}

}

template<class DataType>
const DataType& SList<DataType>::operator[](int aIndex) const
{
	if ((aIndex < fCount) && (aIndex >= 0))
	{
		SinglyLinkedNode<DataType>* Cursor = fTop;
		if (aIndex == 0)
		{
			return (Cursor->getVal());
		}
		for (int i = 0; i < aIndex; i++)
		{
			Cursor = &Cursor->getNxt();
		}
		return (Cursor->getVal());
	}
}
