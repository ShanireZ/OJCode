#include <algorithm>
#include <iostream>
using namespace std;
int jump[505], x[1005], y[1005], g[1005];
struct Edge
{
	int a, b, w;
};
Edge es[1000005];
bool cmp(Edge a1, Edge a2)
{
	return a1.w < a2.w;
}
int find(int a1)
{
	if (a1 != g[a1])
	{
		g[a1] = find(g[a1]);
	}
	return g[a1];
}
int main()
{
	int m, n, pos = 0;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> jump[i];
		jump[i] = jump[i] * jump[i];
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
		cin >> x[i] >> y[i];
		for (int j = i - 1; j >= 1; j--)
		{
			pos++;
			es[pos].w = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			es[pos].a = i, es[pos].b = j;
		}
	}
	sort(es + 1, es + 1 + pos, cmp);
	int maxlen = 0, cnt = 0;
	for (int i = 1; i <= pos; i++)
	{
		int ga = find(es[i].a), gb = find(es[i].b);
		if (ga != gb)
		{
			g[ga] = gb, maxlen = es[i].w;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		if (jump[i] >= maxlen)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}