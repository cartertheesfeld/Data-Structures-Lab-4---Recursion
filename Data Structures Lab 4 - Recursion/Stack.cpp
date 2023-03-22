#include "Stack.h"
//pre:There is no structure to make a linked list
//post: The nodes and the list size exist
Stack::Stack()
{
	topLoc = nullptr;
}
//pre:the destructor doesn't exist and stack needes to be removed
//post:The stack is all gone
Stack::~Stack()
{
	Node* temp;
	while (topLoc != NULL)
	{
		temp = topLoc;
		topLoc = topLoc->next;
		delete temp;
	}
	delete topLoc;

}
//pre: Stack is initalized
//post: it returns true if the list is empty and false if there is an item in the list
bool Stack::IsEmpty()
{
	return (topLoc == NULL);
}
//pre: items have been added to a list
//post: If the memory allocation fails then it returns true else it will return false
bool Stack::IsFull()
{
	try
	{
		Node* temp = new Node;
	}
	catch (bad_alloc)
	{
		return true;
	}
	return false;
}
//pre: Stack is initialized
//post: If stack is full exception is thrown. else an item is added to the top of the list
void Stack::Push(ItemType item)
{
	if (!IsFull())
	{
		Node* temp = new Node;
		temp->item = item;
		temp->next = topLoc;
		topLoc = temp;

	}
}
//pre:There is a stack made of node
//post: the top loc moves to the next node and the other node is outputed
ItemType Stack::Pop()//help
{

	if (!IsEmpty())
	{
		Node* temp = new Node;
		ItemType tempItem = topLoc->item;
		temp = topLoc;
		topLoc = topLoc->next;

		return tempItem;
	}
}
//pre:There is a stack 
//post:now the top of the stack is shown and not removed
ItemType Stack::Top()
{
	return topLoc->item;
}
//pre:There is a stack
//post: The items are saved until there are no more items in the list and send to the InsertAtBottom function
void Stack::Reverse()
{
	if (topLoc != NULL)
	{
		ItemType item;
		item = Pop();
		Reverse();
		InsertAtBottom(item);
	}
}
//pre:The items in the stack have been sent and saved to item
//post: The case starts when it is null. The item is them pushed, but because of the stack frames it is actually pushed at the end. So it pushes all of the other
//items in the list before it pushes the last item because technically it was pushed before the null item was pushed. 
void Stack::InsertAtBottom(ItemType item)
{
	if (topLoc == NULL)
	{
		Push(item);
	}
	else
	{
		ItemType temp = Pop();
		InsertAtBottom(item);
		Push(temp);
	}
}
