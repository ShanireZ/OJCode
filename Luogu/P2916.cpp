#include <iostream>
#include <algorithm>
using namespace std;
int c[10005], g[10005];
struct Way
{
	int x, y, w;
};
Way way[100005];
bool cmp(Way a, Way b)
{
	return a.w < b.w;
}
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
	int n, p, minc = 10000;
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		minc = min(minc, c[i]);
		g[i] = i;
	}
	for (int i = 1; i <= p; i++)
	{
		cin >> way[i].x >> way[i].y >> way[i].w;
		way[i].w *= 2;
		way[i].w += c[way[i].x] + c[way[i].y];
	}
	sort(way + 1, way + 1 + p, cmp);
	int cnt = 0, tot = 0;
	for (int i = 1; i <= p && cnt < n - 1; i++)
	{
		int gx = dfn(way[i].x);
		int gy = dfn(way[i].y);
		if (gx != gy)
		{
			cnt++;
			g[gx] = gy;
			tot += way[i].w;
		}
	}
	cout << tot + minc;
	return 0;
}