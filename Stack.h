#pragma once
#include "NodeIterator.h"

template<class DataType>

class Stack
{
private:
	/*T* fElements;
	int fStackPointer;
	int fStackSize;*/

	NodeIterator<DataType> fElements;
	int fStackSize;

public:
	//Stack();
	Stack(int aSize);

	~Stack();

	bool isEmpty() const;

	int size() const;

	void push(const DataType& aItem);

	void pop();

	const DataType& top() const;
};

//template<class T>
//Stack<T>::Stack()
//{
//	fElements = new T[0];
//	fStackPointer = 0;
//	fStackSize = 0;
//}

template<class DataType>
Stack<DataType>::Stack(int aSize)
{
	if (aSize <= 0)
	{
		throw std::invalid_argument("Illegal stack size");
	}
	else
	{
		/*fElements = new T[aSize];
		fStackPointer = 0;*/

		fStackSize = aSize;
	}
}

template<class DataType>
Stack<DataType>::~Stack()
{
	//delete[] fElements;
}

template<class DataType>
bool Stack<DataType>::isEmpty() const
{
	return fElements.size() == 0;
}

template<class DataType>
int Stack<DataType>::size() const
{
	return fElements.size();
}

// the push methods stores a item at the next free slot
// in the stack, if there is room
template<class DataType>
void Stack<DataType>::push(const DataType& aItem)
{
	if (fElements.size() < fStackSize)
	{
		fElements.push_front(aItem);
		//fElements[fStackPointer++] = aItem;
	}
	else
	{
		throw std::overflow_error("Stack full! ");
	}
}

// the pop method shifts the stack pointer to the previous
// slot in the stack, if there is such a slot. 
// Note, the element in the current slot it self is not yet destroyed
template<class DataType>
void Stack<DataType>::pop()
{
	if (!isEmpty())
	{
		fElements.pop_front();
		//fStackPointer--;
	}
	else
	{
		throw std::underflow_error("Stack empty! ");
	}
}

// the top method returns a const reference to the
// item in the current slot in the stack, if there is 
// such a slot
template<class DataType>
const DataType& Stack<DataType>::top() const
{
	if (!isEmpty())
	{
		//return fElements[fStackPointer - 1];
		return fElements[0];
	}
	else
	{
		throw std::underflow_error("Stack empty! ");
	}
}