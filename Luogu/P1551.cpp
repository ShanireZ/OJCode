#include <iostream>
using namespace std;
int g[5005];
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
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		int ga = dfn(a), gb = dfn(b);
		if (ga != gb)
		{
			g[ga] = gb;
		}
	}
	for (int i = 1; i <= p; i++)
	{
		int a, b;
		cin >> a >> b;
		int ga = dfn(a), gb = dfn(b);
		if(ga == gb)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}