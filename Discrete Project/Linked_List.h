#pragma once
#ifndef Linked List_h
#include<iostream>
using namespace std;
#endif // !Linked List_h
struct node
{
	int v1, v2, weight;
	node* next;
};
class LL
{
	node* head;
	node* curr;
	int count;
public:
	LL()
	{
		head = NULL;
		curr = NULL;
		count = 0;
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
	node* create_node(int v1, int v2, int wei)
	{
		node* temp = new node;
		temp->v1 = v1;
		temp->v2 = v2;
		temp->weight = wei;
		temp->next = NULL;
		return temp;
	}
	void insert_end(int v1, int v2, int wei)
	{
		if (isempty())
		{
			head = create_node(v1, v2, wei);
			curr = head;
			count++;
		}
		else
		{
			node* temp = create_node(v1, v2, wei);
			count++;
			curr->next = temp;
			curr = temp;
		}
	}
	void display()
	{
		node* temp = head;
		cout << "{ ";
		while (temp != NULL)
		{
			cout << "(" << temp->v1 << "," << temp->v2 << "," << temp->weight << ") ";
			temp = temp->next;
		}
		cout << "}";
	}
	int get_count()
	{
		return count;
	}
	node* get_head()
	{
		return head;
	}

	void sort()
	{
		node* temp = head;
		node* temp1 = NULL;
		while (temp != NULL)
		{
			temp1 = temp->next;
			while (temp1 != NULL)
			{
				if (temp->weight > temp1->weight)
				{
					swap(temp->v1, temp1->v1);
					swap(temp->v2, temp1->v2);
					swap(temp->weight, temp1->weight);
				}
				temp1 = temp1->next;
			}
			temp = temp->next;
		}
	}
	void delete_node(node* temp)
	{
		node* curr = head;
		if (isempty())
		{
			cout << "List is empty" << endl;
		}
		else
		{
			while (curr->next != temp)
			{
				curr = curr->next;
			}
			curr->next = temp->next;
			delete temp;

		}
	}
	void remove_dup()
	{
		node* del = new node;
		node* del1 = new node;
		node* temp = head;
		node* temp1 = NULL;
		while (temp != NULL)
		{
			temp1 = temp->next;
			while (temp1 != NULL)
			{
				del = temp1->next;
				if (temp->v1 == temp1->v2 && temp->v2 == temp1->v1)
				{
					delete_node(temp1);
				}
				temp1 = del;
			}
			temp = temp->next;
		}
	}
};

