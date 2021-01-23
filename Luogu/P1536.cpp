#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int g[1005];
int dfn(int x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int n, m;
	cin >> n;
	while (n != 0)
	{
		cin >> m;
		for (int i = 1; i <= n; i++)
		{
			g[i] = i;
		}
		int t = 0;
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			cin >> a >> b;
			int ga = dfn(a), gb = dfn(b);
			if (ga != gb)
			{
				t++;
				g[ga] = gb;
			}
		}
		cout << (n - 1) - t << endl;
		cin >> n;
	}
	return 0;
}