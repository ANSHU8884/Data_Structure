#include<iostream>
using namespace std;
int a[10][10];
int i, j, k, m, n;

void read_graph()
{
	cout << "enter number of vertices in the graph\n";
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			a[i][j] = 0;
		}
	}
	cout << "\n enter how many edges in graph\n";
	cin >> k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << "enter starting and ending vertex of graph\n";
			cin >> j >> m;
			a[m][j] = 1;
			a[j][m] = 1;
		}
	}
}
void display_graph()
{
	cout << "graph is\n";
	for (int i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	read_graph();
	display_graph();
	return 0;
}