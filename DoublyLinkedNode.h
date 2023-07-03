#pragma once
template<class DataType>

class DoublyLinkedNode
{
public: typedef DoublyLinkedNode<DataType> Node;

private: DataType fVal;
	     Node* fNxt;
	     Node* fPrev;
		 DoublyLinkedNode()
		 {
			 fVal	= DataType();
			 fNxt	= &NIL;
			 fPrev	= &NIL;
		 }

public: static Node NIL;
	   DoublyLinkedNode(const DataType& aVal);
	   void prepend(Node& aNode);
	   void append(Node& aNode);
	   void remove();

	   // getters
	   DataType& getVal() { return fVal; }
	   Node& getNxt()	  { return *fNxt; }
	   Node& getPrev()	  { return *fPrev; }
};

// nil represent head and tail of doubly-linked list
template<class DataType>
DoublyLinkedNode<DataType> DoublyLinkedNode<DataType>::NIL;

template<class DataType>
DoublyLinkedNode<DataType>::DoublyLinkedNode(const DataType& aVal)
{
	fVal  = aVal;
	fNxt  = &NIL;
	fPrev = &NIL;
}

template<class DataType>
void DoublyLinkedNode<DataType>::prepend(Node& aNode)
{
	aNode.fNxt = this; 
	if (fPrev != &NIL) 
	{ 
		aNode.fPrev = fPrev;
		fPrev->fNxt = &aNode;
	}
	fPrev = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::append(Node& aNode)
{
	aNode.fPrev = this;
	if (fNxt != &NIL)
	{ 
		aNode.fNxt = fNxt;
		fNxt->fPrev = &aNode;
	}
	fNxt = &aNode;
}

template<class DataType>
void DoublyLinkedNode<DataType>::remove()
{
	if (fNxt == &NIL)
	{
		fPrev->fNxt = &NIL;
	}
	else if (fPrev == &NIL)
	{
		fNxt->fPrev = &NIL;
	}
	else
	{
		fPrev->fNxt = fNxt;
		fNxt->fPrev = fPrev;
	}

	delete this;
}
