#include<iostream>
using namespace std;
int g[10][10], n, e, visited[10];
int i, j, a, b;
void dfs(int a)
{
	visited[a] = 1;
	cout << a << " ";
	for (i = 1; i <= n; i++)
	{
		if (!visited[i] && g[a][i] == 1)
		{
			dfs(i);
		}
	}
}
int main()
{
	cout << "enter the no of vertices in graph\n";
	cin >> n;
	cout << "enter Adjacency matrix\n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cin >> g[i][j];

		}
		cout << "\n";
	}

	cout << "adjancency graph \n";
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << g[i][j];

		}
		cout << "\n";
	}
	for (i = 1; i <= n; i++)
	{
		visited[i] = 0;
		cout << "depth first search is" << endl;
		dfs(1);
	}
	return 0;
}