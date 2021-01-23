#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int g[2005];
struct Line
{
	int x, y, w;
};
vector<Line> line;
bool cmp(Line a, Line b)
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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		Line tmp;
		cin >> tmp.x >> tmp.y >> tmp.w;
		line.push_back(tmp);
	}
	sort(line.begin(), line.end(), cmp);
	int cnt = 0, maxl = 0;
	for (int i = 0; i < m && cnt != n - 1; i++)
	{
		int gx = dfn(line[i].x), gy = dfn(line[i].y);
		if (gx != gy)
		{
			g[gx] = gy;
			maxl = max(maxl, line[i].w);
		}
	}
	cout << maxl;
	return 0;
}