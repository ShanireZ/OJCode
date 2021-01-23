#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Node
{
	int x, y, v;
};
Node p[405];
bool cmp(Node a, Node b)
{
	return a.v > b.v;
}
int main()
{
	int m, n, k;
	cin >> m >> n >> k;
	int pos = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> p[pos].v;
			p[pos].x = i;
			p[pos].y = j;
			pos++;
		}
	}
	sort(p, p + m * n, cmp);
	int sx = 0, sy = p[0].y;
	int total = 0;
	pos = 0;
	while (k > 0 && pos <= m * n)
	{
		int dis = abs(p[pos].x - sx) + abs(p[pos].y - sy) + p[pos].x + 1;
		if (k >= dis)
		{
			k -= dis - p[pos].x;
			total += p[pos].v;
			sx = p[pos].x;
			sy = p[pos].y;
			pos++;
		}
		else
		{
			break;
		}
	}
	cout << total;
	return 0;
}