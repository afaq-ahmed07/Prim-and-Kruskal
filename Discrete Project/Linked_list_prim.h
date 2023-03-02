#pragma once
#ifndef Linked_list_prim
#include<iostream>
using namespace std;
#endif // !Linked_list_prim
struct node
{
	char vertex;
	int weight;
	node* next;
};
class LL
{
	node* head = nullptr;
	node* curr = nullptr;
	int count;
public:
	LL()
	{
		head = nullptr;
		curr = nullptr;
	}
	bool isempty()
	{
		if (head == NULL)
		{
			return true;
		}
		else
			return false;
	}
	node* create_node(char vertex,int wei)
	{
		node* temp = new node;
		temp->vertex = vertex;
		temp->weight = wei;
		temp->next = NULL;
		return temp;
	}
	void insert_end(char vertex,int wei)
	{
		if (isempty())
		{
			head = create_node(vertex,wei);
			curr = head;
		}
		else
		{
			node* temp = create_node(vertex, wei);
			curr->next = temp;
			curr = curr->next;
		}
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->vertex << " ";
			temp = temp->next;
		}
	}

};

