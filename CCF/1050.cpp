#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, k, x, y, z;
	cin >> n >> m >> k;
	int a[n][m], b[m][k], c[n][k];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < m; y++)
		{
			cin >> a[x][y];
		}
	}
	for (x = 0; x < m; x++)
	{
		for (y = 0; y < k; y++)
		{
			cin >> b[x][y];
		}
	}
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < k; y++)
		{
			for (z = 0; z < m; z++)
			{
				c[x][y] += a[x][z] * b[z][y];
			}
		}
	}
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < k; y++)
		{
			cout << c[x][y] << " ";
		}
		cout << endl;
	}
	return 0;
}
