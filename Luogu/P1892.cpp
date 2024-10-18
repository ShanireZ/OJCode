#include <iostream>
using namespace std;
int g[2005], n, m, ans;
int dfn(int x)
{
	return x == g[x] ? x : g[x] = dfn(g[x]);
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n * 2; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		int gx = dfn(x), gy = dfn(y), egx = dfn(x + n), egy = dfn(y + n);
		(ch == 'F') ? (g[gx] = gy) : (g[egx] = gy, g[egy] = gx);
	}
	for (int i = 1; i <= n; i++)
	{
		ans += (i == g[i]);
	}
	cout << ans << endl;
	return 0;
}