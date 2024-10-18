#include <iostream>
using namespace std;
int g[150005], n, k, ans;
int dfn(int x)
{
	return x == g[x] ? x : g[x] = dfn(g[x]);
}
int main()
{
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
			ans++;
			continue;
		}
		int ax = dfn(x), ay = dfn(y);
		int bx = dfn(x + n), by = dfn(y + n);
		int cx = dfn(x + n * 2), cy = dfn(y + n * 2);
		if (t == 1)
		{
			if (ax == by || ax == cy) //! 已有x吃y 或 y吃x
			{
				ans++;
				continue;
			}
			g[ax] = ay, g[bx] = by, g[cx] = cy;
		}
		else
		{
			if (ax == ay || ax == cy) //! 已有x和y同类 或 y吃x
			{
				ans++;
				continue;
			}
			g[ax] = by, g[bx] = cy, g[cx] = ay;
		}
	}
	cout << ans << endl;
	return 0;
}