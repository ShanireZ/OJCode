#include <iostream>
using namespace std;
int g[150005];
int dfn(int x)
{
	if (x != g[x])
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int n, k, tot = 0;
	cin >> n >> k;
	for (int i = 1; i <= n * 3; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= k; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (x > n || y > n)
		{
			tot++;
			continue;
		}
		int ax = dfn(x), ay = dfn(y);
		int bx = dfn(x + n), by = dfn(y + n);
		int cx = dfn(x + n * 2), cy = dfn(y + n * 2);
		if (t == 1)
		{
			if (ax == by || ax == cy) //!已有x吃y 或 y吃x
			{
				tot++;
				continue;
			}
			g[ax] = ay, g[bx] = by, g[cx] = cy;
		}
		else
		{
			if (ax == ay || ax == cy) //!已有x和y同类 或 y吃x
			{
				tot++;
				continue;
			}
			g[ax] = by, g[bx] = cy, g[cx] = ay;
		}
	}
	cout << tot;
	return 0;
}