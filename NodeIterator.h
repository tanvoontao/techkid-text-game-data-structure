#pragma once
#include "SinglyLinkedNode.h"

template<class DataType>
class NodeIterator
{
private:
	SinglyLinkedNode<DataType>* fTop;
	SinglyLinkedNode<DataType>* fLast;
	int fCount;
	int fCurrIndex;

public:
	// typedef NodeIterator<DataType> Iterator;
	NodeIterator(int aCurrIndex);
	NodeIterator();
	~NodeIterator();
	const DataType& operator*() const;
	
	NodeIterator<DataType>& operator++(); // prefix
	NodeIterator<DataType> operator++(int); // useless
	
	NodeIterator<DataType>& operator--();
	NodeIterator<DataType> operator--(int); // useless

	bool operator==(const NodeIterator<DataType>& aOther) const;
	bool operator!=(const NodeIterator<DataType>& aOther) const;

	NodeIterator<DataType> begin();
	NodeIterator<DataType> end();

	bool isEmpty() const;
	int size() const;
	void find(const DataType& aElement);
	void push_front(const DataType& aElement);
	void pop_front();
	void pop_back();
	void remove(const DataType& aElement);
	const DataType& operator[](int aIndex) const;
};

template<class DataType>
NodeIterator<DataType>::NodeIterator()
{
	fTop = &SinglyLinkedNode<DataType>::NIL;
	fLast = &SinglyLinkedNode<DataType>::NIL;
	fCount = 0;
	fCurrIndex = 0;
}

template<class DataType>
NodeIterator<DataType>::NodeIterator(int aCurrIndex)
{
	fTop = &SinglyLinkedNode<DataType>::NIL;
	fLast = &SinglyLinkedNode<DataType>::NIL;
	fCount = 0;
	fCurrIndex = aCurrIndex;
}

template<class DataType>
NodeIterator<DataType>::~NodeIterator()
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
bool NodeIterator<DataType>::isEmpty() const
{
	if (fCount == 0)
		return true;
	else
		return false;
}

template<class DataType>
int NodeIterator<DataType>::size() const
{
	return fCount;
}

template<class DataType>
void NodeIterator<DataType>::find(const DataType& aElement)
{

}

template<class DataType>
void NodeIterator<DataType>::push_front(const DataType& aElement)
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
void NodeIterator<DataType>::pop_front()
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
void NodeIterator<DataType>::pop_back()
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
void NodeIterator<DataType>::remove(const DataType& aElement)
{
	SinglyLinkedNode<DataType>* Temp = fTop;
	//int index = fCount - 1;

	SinglyLinkedNode<DataType>* theNodeInFront = &(SinglyLinkedNode<DataType>::NIL);


	if (!isEmpty())
	{
		for (int i = 0; i < fCount; i++)
		{
			if (Temp->getVal().name == aElement.name)
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
const DataType& NodeIterator<DataType>::operator[](int aIndex) const
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

template<class DataType>
const DataType& NodeIterator<DataType>::operator*() const
{
	return operator[](fCurrIndex);
}

template<class DataType>
NodeIterator<DataType>& NodeIterator<DataType>::operator++()
{
	fCurrIndex++;
	return *this;
}

// got issue
template<class DataType>
NodeIterator<DataType> NodeIterator<DataType>::operator++(int)
{
	NodeIterator<DataType> temp = *this;
	fCurrIndex++;
	return temp;
}

template<class DataType>
NodeIterator<DataType>& NodeIterator<DataType>::operator--()
{
	fCurrIndex--;
	return *this;
}

template<class DataType>
bool NodeIterator<DataType>::operator==(const NodeIterator<DataType>& aOther) const
{
	return (fCurrIndex == aOther.fCurrIndex);
}

template<class DataType>
bool NodeIterator<DataType>::operator!=(const NodeIterator<DataType>& aOther) const
{
	return !(*this == aOther);
}

template<class DataType>
NodeIterator<DataType> NodeIterator<DataType>::end()
{
	return (NodeIterator<DataType>(fCount));
}

template<class DataType>
NodeIterator<DataType> NodeIterator<DataType>::begin()
{
	return (NodeIterator<DataType>(0));
}