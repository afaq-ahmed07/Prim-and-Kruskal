#include<iostream>
#include"Linked_List.h"
using namespace std;

struct edge
{
	int value, wei;//value either 1 or 0 and weight
};

class Graph
{
	edge** G;//graph pointer
	int row, column;
	LL min_edges;//list of min_edges
	edge** mst;//mst pointer
	int cost;
public:
	Graph()//constructor
	{
		G = NULL;
		row = 0;
		column = 0;
		mst = NULL;
		cost = 0;
	}
	void adj_matrix()
	{
		int x, y, wei;
		cout << "Enter Number of Vertices:";
		cin >> row;
		column = row;
		G = new edge * [row];
		for (int i = 1; i <= row; i++)
		{
			G[i] = new edge[column];//array of pointers
		}

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= column; j++)
			{
				G[i][j].value = 0;//initializing with 0
				G[i][j].wei = 0;
			}
		}

		for (int i = 1; i <= row * column; i++)
		{
			cout << "Enter row:";
			cin >> y;
			cout << "Enter column:";
			cin >> x;
			cout << "Enter weight of edge:";
			cin >> wei;
			if (x > 0 && x <= column || y > 0 && y <= row)
			{
				G[y][x].value = 1;//setting value 1 at y row and x column
				G[y][x].wei = wei;

				G[x][y].value = 1;
				G[x][y].wei = wei;
			}
			else
			{
				break;
			}
		}

	}
	void display_mat()
	{
		char ch = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << ch << ": ";
			for (int j = 1; j <= column; j++)
			{
				cout << G[i][j].value << " ";//displaying matrix
			}
			ch++;
			cout << endl;
		}
	}

	void calculate_cost_G()//calculating cost of graph
	{
		cost = 0;
		for (int i = 1; i <=row; i++)
		{
			for (int j = i+1; j <=column; j++)
			{
				if (G[i][j].wei != 0)
				{
					cost += G[i][j].wei;
				}
			}
		}
		cout << "Total Cost" << cost << endl;
	}

	void sort_edges()//sorting edges
	{
		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= column; j++)
			{
				if (G[i][j].wei != 0)
				{
					min_edges.insert_end(i, j, G[i][j].wei);//inserting in linked list
				}
			}
		}
		min_edges.sort();//sorting in ascending order
		min_edges.remove_dup();//removing if v1 and v2 of next node is same
	}

	void display_edges()
	{
		min_edges.display();//displaing linked list
	}
	void Kruskal()
	{
		bool* visited = new bool[row];//visited array
		mst = new edge * [row];
		int i = 1, j = 1, count = 0;
		for (int j = 1; j <= column; j++)
		{
			visited[j] = false;
		}
		for (int i = 1; i <= row; i++)
		{
			mst[i] = new edge[column];
		}

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= column; j++)
			{
				mst[i][j].value = 0;
				mst[i][j].wei = 0;
			}
		}
		node* temp = min_edges.get_head();//getting head of linked list

		while (temp != NULL && count < row - 1)
		{
			i = temp->v1;
			j = temp->v2;
			if (!visited[j])//if not visited add it to mst
			{
				mst[i][j].value = 1;
				mst[i][j].wei = temp->weight;
				mst[j][i].value = 1;
				mst[j][i].wei = temp->weight;
				if (temp == min_edges.get_head())
					visited[i] = true;
				visited[j] = true;
				count++;
			}
			temp = temp->next;
		}
	}
	void display_mst()
	{
		char ch = 'A';
		for (int i = 1; i <= row; i++)
		{
			cout << ch << ": ";
			for (int j = 1; j <= column; j++)
			{
				cout << mst[i][j].wei << " ";//displaying mst
			}
			ch++;
			cout << endl;
		}
	}
	void calculate_cost_mst()
	{
		cost = 0;
		for (int i = 1; i <= row ; i++)
		{
			for (int j = i+1; j <= column ; j++)
			{
				if (mst[i][j].wei != 0)
				{
					cost += mst[i][j].wei;
				}
			}
		}
		cout << "Total Cost:" << cost << endl;
	}
};
int main()
{

	Graph g;
	g.adj_matrix();//making adjacency matrix
	g.display_mat();//displaying matrix
	g.calculate_cost_G();
	cout << endl;

	g.sort_edges();
	g.display_edges();
	cout << endl;

	g.Kruskal();//making mst
	g.display_mst();
	g.calculate_cost_mst();
	return 0;
}