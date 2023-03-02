//#include<iostream>
//using namespace std;
//struct edge
//{
//	int wei = 0, value = 0;//wei and value
//};
//class Graph
//{
//	edge** graph;//pointer pointing to graph
//	int row, column;
//	edge** mst;//pointer pointing to mst
//public:
//	Graph()
//	{
//		graph = NULL;
//		row = 0;
//		column = 0;
//		mst = NULL;
//	}
//	void adj_matrix()
//	{
//		int x, y, wei;
//		cout << "Enter Number of Vertices:";
//		cin >> row;
//		column = row;
//		graph = new edge * [row];
//		for (int i = 1; i <= row; i++)
//		{
//			graph[i] = new edge[column];//array of pointers
//		}
//
//		for (int i = 1; i <= row; i++)
//		{
//			for (int j = 1; j <= column; j++)
//			{
//				graph[i][j].wei = 0;//initializing graph
//				graph[i][j].value = 0;
//			}
//		}
//		for (int i = 1; i <= row * column; i++)
//		{
//			cout << "Enter row:";
//			cin >> y;
//			cout << "Enter column:";
//			cin >> x;
//			cout << "Enter weight of edge:";
//			cin >> wei;
//
//			if (x > 0 && x <= column || y > 0 && y <= row)
//			{
//				graph[y][x].value = 1;//if edge 1 other 0
//				graph[y][x].wei = wei;
//
//				graph[x][y].value = 1;
//				graph[x][y].wei = wei;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//
//	void calculate_cost_G()//calculating cost of graph
//	{
//		int cost = 0;
//		for (int i = 1; i <= row; i++)
//		{
//			for (int j = i + 1; j <= column; j++)
//			{
//				if (graph[i][j].wei != 0)
//				{
//					cost += graph[i][j].wei;
//				}
//			}
//		}
//		cout << "Total Cost:" << cost << endl;
//	}
//
//	void display_mat()//displaying matrix
//	{
//		char ch = 'A';
//		for (int i = 1; i <= row; i++)
//		{
//			cout << ch << ": ";
//			for (int j = 1; j <= column; j++)
//			{
//				cout << graph[i][j].value << " ";
//			}
//			ch++;
//			cout << endl;
//		}
//	}
//	void make_it_dissapear(int& i, int& j)//To remove if edge is placed in mst
//	{
//		graph[i][j].wei = 0;
//		graph[j][i].wei = 0;
//	}
//	void Prim()//calculating mst using prim algo
//	{
//		int* arr = new int[row];//array for visited
//		int i = 1, j = 1, count_ed = 0, arr_count = 0, temp_j = 1, temp_i=1;
//		bool edge_checker_j = false, edge_checker_i = false, edge_check = true;
//		mst = new edge * [row];
//		for (int i = 1; i <= row; i++)
//		{
//			mst[i] = new edge[column];
//		}
//		for (int i = 1; i <= row; i++)
//		{
//			for (int j = 1; j <= column; j++)
//			{
//				mst[i][j].wei = 0;//initializing mst
//				mst[i][j].value = 0;
//			}
//		}
//		int max_wei = INT_MAX, max_value = 0;//initializing max value that can be entered in int
//		for (j = 1; j <= column; j++)
//		{
//			if (graph[i][j].wei != 0)
//			{
//				if (graph[i][j].wei < max_wei)//finding minimum weight edge
//				{
//					temp_i=1;
//					temp_j = j;
//					max_wei = graph[i][j].wei;
//					max_value = graph[i][j].value;
//
//				}
//			}
//		}
//		mst[temp_i][temp_j].value = max_value;//putting in mst
//		mst[temp_i][temp_j].wei = max_wei;
//
//		mst[temp_j][temp_i].value = max_value;//putting in reverse
//		mst[temp_j][temp_i].wei = max_wei;
//
//		count_ed++;
//		make_it_dissapear(temp_i, temp_j);
//		arr[arr_count++] = i;//visited
//		arr[arr_count++] = temp_j;
//		while (count_ed < row-1)
//		{
//			max_wei = INT32_MAX;
//			i = 0;
//			for (arr[i]; i < arr_count; i++)
//			{
//				for (j = 1; j <= column; j++)
//				{
//					if (graph[arr[i]][j].wei != 0)
//					{
//						if (max_wei > graph[arr[i]][j].wei)//minimum in graph
//						{
//							max_wei = graph[arr[i]][j].wei;
//							max_value = graph[arr[i]][j].value;
//							temp_i = arr[i];
//							temp_j = j;
//						}
//
//					}
//				}
//			}
//			i = 0;
//			for (arr[i];  i<arr_count; i++)//to check if visited or not
//			{
//				if (temp_j == arr[i])
//				{
//					edge_check = false;
//				}
//
//			}
//			if (edge_check == true)//if !visited
//			{
//				mst[temp_i][temp_j].value = max_value;
//				mst[temp_i][temp_j].wei = max_wei;
//
//				mst[temp_j][temp_i].value = max_value;
//				mst[temp_j][temp_i].wei = max_wei;
//				count_ed++;
//				make_it_dissapear(temp_i, temp_j);
//			}
//			for (int k = 1; k < arr_count; k++)//if edge already not exsist in array
//			{
//				if (temp_i == arr[k])//if exsist true
//				{
//					edge_checker_i = true;
//				}
//				if (temp_j == arr[k])
//				{
//					edge_checker_j = true;
//				}
//			}
//			if (edge_checker_i == false)
//			{
//				arr[arr_count++] = temp_j;
//			}
//
//			if (edge_checker_j == false)
//			{
//				arr[arr_count++] = temp_j;
//			}
//		}
//	}
//	void display_mst()//displaying mst
//	{
//		char ch = 'A';
//		for (int i = 1; i <= row; i++)
//		{
//			cout << ch << ": ";
//			for (int j = 1; j <= column; j++)
//			{
//				cout << mst[i][j].wei << " ";
//			}
//			ch++;
//			cout << endl;
//		}
//	}
//
//	void calculate_cost_mst()//calculating cost of mst
//	{
//		int cost = 0;
//		for (int i = 1; i <= row; i++)
//		{
//			for (int j = i + 1; j <= column; j++)
//			{
//				if (mst[i][j].wei != 0)
//				{
//					cost += mst[i][j].wei;//cost of minimum spanning tree
//				}
//			}
//		}
//		cout << "Total Cost:" << cost << endl;
//	}
//};
//int main()
//{
//	Graph g;
//	g.adj_matrix();
//	g.display_mat();
//	g.calculate_cost_G();
//	g.Prim();
//	cout << endl;
//	g.display_mst();
//	g.calculate_cost_mst();
//	return 0;
//}