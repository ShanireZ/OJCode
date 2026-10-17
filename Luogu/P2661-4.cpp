#include <iostream>
#include <algorithm>
using namespace std;
int g[200005]; //anc編號
int d[200005]; //到anc的距離
int minl = 0x3f3f3f3f;
int dfn(int x)
{
	if (x != g[x])
	{
		int anc = g[x];
		g[x] = dfn(g[x]);
		d[x] = d[x] + d[anc];
	}
	return g[x];
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int gx = dfn(x);
		if (i != gx)
		{
			g[i] = gx;
			d[i] = d[x] + 1;
		}
		else
		{
			minl = min(minl, d[x] + 1); //環長度=環尾到環頭距離+1
		}
	}
	cout << minl;
	return 0;
}