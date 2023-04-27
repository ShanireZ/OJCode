#include <iostream>
using namespace std;
int mx[25][25], prim[505], vis[10005], pos;
int main()
{
	int n, tx, ty;
	cin >> n >> tx >> ty;
	for (int i = 2; pos < n * n; i++)
	{
		if (vis[i] == 0)
		{
			prim[++pos] = i;
		}
		for (int j = 1; j <= pos && prim[j] * i <= 10000; j++)
		{
			vis[prim[j] * i] = 1;
			if (i % prim[j] == 0)
			{
				break;
			}
		}
	}
	int x = 1, y = 0, id = 1;
	while (id <= n * n)
	{
		while (mx[x][y + 1] == 0 && y + 1 <= n)
		{
			mx[x][++y] = prim[id++];
		}
		while (mx[x + 1][y] == 0 && x + 1 <= n)
		{
			mx[++x][y] = prim[id++];
		}
		while (mx[x][y - 1] == 0 && y - 1 >= 1)
		{
			mx[x][--y] = prim[id++];
		}
		while (mx[x - 1][y] == 0 && x - 1 >= 1)
		{
			mx[--x][y] = prim[id++];
		}
	}
	cout << mx[tx][ty] << "\n";
	return 0;
}