#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int g[105];
struct Line
{
	int x, y, f;
};
vector<Line> line;
bool cmp(Line a, Line b)
{
	return a.f < b.f;
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
	int n, k, tot = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		g[i] = i;
	}
	for (int i = 1; i <= k; i++)
	{
		Line tmp;
		cin >> tmp.x >> tmp.y >> tmp.f;
		line.push_back(tmp);
		tot += tmp.f;
	}
	sort(line.begin(), line.end(), cmp);
	for (int i = 0; i < line.size(); i++)
	{
		int gx = dfn(line[i].x), gy = dfn(line[i].y);
		if (gx != gy)
		{
			g[gx] = gy;
			tot -= line[i].f;
		}
	}
	cout << tot;
	return 0;
}