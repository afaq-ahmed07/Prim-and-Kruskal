#pragma once
#ifndef Stack_h
#include<iostream>//Stack using linked List
using namespace std;
#endif // !Stack_h
struct Node
{
	int data;
	Node* next;
};
Node* top = NULL;
void push(int x)
{
	Node* t;
	t = new Node;

	if (t == NULL)
	{
		cout << "stack is full\n";
	}
	else
	{
		t->data = x;
		t->next = top;
		top = t;
	}

}
int pop()
{
	Node* t;
	int x = -1;

	if (top == NULL)
	{
		cout << "Stack is Empty\n";
	}
	else
	{
		t = top;
		top = top->next;//top moves one step further
		x = t->data;
		delete t;//deleting t
	}
	return x;
}
bool isempty()
{
	if (top == NULL)
	{
		return true;
	}
	return false;
}