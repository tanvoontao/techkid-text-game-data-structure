#pragma once
template<class DataType>

class SinglyLinkedNode
{
public: typedef SinglyLinkedNode<DataType> Node;

private: 
	DataType fVal;
	Node* fNxt;
	SinglyLinkedNode()
	{
		fVal = DataType();
		fNxt = &NIL;
	}

public: static Node NIL;
	SinglyLinkedNode(const DataType& aVal);
	void insertAtTheTop(Node& aNode);
	void remove();

	// getters
	DataType& getVal() { return fVal; }
	Node& getNxt() { return *fNxt; }

	void setNxt(Node* aNode) { fNxt = aNode; }
};

template<class DataType>
SinglyLinkedNode<DataType> SinglyLinkedNode<DataType>::NIL;

template<class DataType>
SinglyLinkedNode<DataType>::SinglyLinkedNode(const DataType& aVal)
{
	fVal = aVal;
	fNxt = &NIL;
}

template<class DataType>
void SinglyLinkedNode<DataType>::insertAtTheTop(Node& aNode)
{
	aNode.fNxt = this;
}

template<class DataType>
void SinglyLinkedNode<DataType>::remove()
{
	/*
	if (nodeInFront == &NIL) // meaning wan to remove first node
	{
		aTop = fNxt;
	}
	else if (fNxt == &NIL) // meaning wan to remove last node
	{
		nodeInFront.fNxt = &NIL
	}
	else if (nodeInFront != &NIL && fNxt != &NIL)
	{
		nodeInFront.fNxt = fNxt;
	}
	*/

	delete this;
}