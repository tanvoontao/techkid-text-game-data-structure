#pragma once
#include "List.h"


template<class DataType>
class Queue
{
private: List<DataType> fElements;

public:
	bool isEmpty() const;
	int size() const;
	void enqueue(const DataType& aElement);
	DataType dequeue();
};

template<class DataType>
bool Queue<DataType>::isEmpty() const
{
	return fElements.isEmpty();
}

template<class DataType>
int Queue<DataType>::size() const
{
	return fElements.size();
}

template<class DataType>
void Queue<DataType>::enqueue(const DataType& aElement)
{
	fElements.push_back(aElement);
}

template<class DataType>
DataType Queue<DataType>::dequeue()
{
	if (!isEmpty())
	{
		DataType value = fElements[0];
		//const DataType& Result	= fElements[0];
		fElements.pop_front();
		return value;
	}
	else
	{
		throw std::underflow_error("Queue is empty! ");
	}
}