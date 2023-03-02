#pragma once
#ifndef Queue_h
#include <iostream>//Queue using Linked List
using namespace std;
#endif // !Queue_h
struct Node
{
	int data;
	Node* next;
};
Node* front = NULL, * rear = NULL;//node for front and back
void enqueue(int x)
{
	Node* t;
	t = new Node;//temporary node
	if (t == NULL)
		cout << "Queue is FUll\n";
	else
	{
		t->data = x;
		t->next = NULL;
		if (front == NULL)//if first element
			front = rear = t;
		else
		{
			rear->next = t;//else point rear to t
			rear = t;//make rear t
		}
	}

}
int dequeue()
{
	int x = -1;
	Node* t;

	if (front == NULL)
		cout << "Queue is Empty\n";
	else
	{
		x = front->data;//saving value in x
		t = front;
		front = front->next;//moving front
		delete t;
	}
	return x;
}
bool isEmpty()
{
	if (front == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}