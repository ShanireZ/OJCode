#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
	int v, w;
};
vector<Edge> es[5005];
queue<int> q;
int dis[5005], t[5005], vis[5005], n, m;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		es[b].push_back(Edge{a, c});
	}
	for (int i = 1; i <= n; i++)
	{
		es[n + 1].push_back(Edge{i, 0});
	}
	fill(dis, dis + n + 1, 0x3f3f3f3f);
	q.push(n + 1), vis[n + 1] = t[n + 1] = 1;
	while (q.size())
	{
		int now = q.front();
		q.pop(), vis[now] = 0;
		for (Edge e : es[now])
		{
			int nxt = e.v, w = e.w;
			if (dis[nxt] > dis[now] + w)
			{
				dis[nxt] = dis[now] + w;
				if (vis[nxt] == 0)
				{
					q.push(nxt), vis[nxt] = 1, t[nxt]++;
					if (t[nxt] > n)
					{
						cout << "NO" << endl;
						return 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	return 0;
}