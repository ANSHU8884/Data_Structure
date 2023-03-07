#include<iostream>
using namespace std;
int i, j, n, e, visited[10];
int g[10][10];
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
	cout << "enter no of vertices in graph\n";
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
	cout << "adjacency graph is\n";
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
		return 0;
	}
}