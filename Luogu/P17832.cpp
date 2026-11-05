#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct Edge
{
	long long r, t;
};
vector<Edge> es[500005];
int c, n, m, d, q, w[500005];
long long res, dis[505][505];
int main()
{
	memset(dis, 0x3f, sizeof(dis));
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		dis[i][i] = 0;
		while (k--)
		{
			int a, t;
			cin >> a >> t;
			es[a].push_back(Edge{i, t});
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (Edge ex : es[i])
		{
			for (Edge ey : es[i])
			{
				dis[ex.r][ey.r] = min(dis[ex.r][ey.r], ex.t + ey.t);
				dis[ey.r][ex.r] = dis[ex.r][ey.r];
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	while (q--)
	{
		res = 0x3f3f3f3f3f3f3f3f;
		int x, y;
		cin >> x >> y;
		for (Edge ex : es[x])
		{
			for (Edge ey : es[y])
			{
				res = min(res, w[x] + w[y] + ex.t + ey.t + dis[ex.r][ey.r]);
			}
		}
		cout << res << "\n";
	}
	return 0;
}