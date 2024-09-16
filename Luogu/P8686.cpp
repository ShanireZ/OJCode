#include <algorithm>
#include <iostream>
using namespace std;
int g[200005];
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
	int n;
	cin >> n;
	for (int i = 1; i <= n * 2; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		int now = dfn(a);
		cout << now << " ";
		g[now] = dfn(now + 1);
	}
	return 0;
}
// TAG: 并查集