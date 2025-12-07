#include <algorithm>
#include <iostream>
using namespace std;
int a[505][505], n, m;
int main()
{
	cin >> n >> m;
	for (int j = 1; j <= m; j++)
	{
		if (j % 2 == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				a[i][j] = 1;
			}
		}
		else
		{
			j % 4 == 0 ? a[1][j] = 1 : a[n][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << (a[i][j] == 1 ? 'x' : '.');
		}
		cout << endl;
	}
	return 0;
}