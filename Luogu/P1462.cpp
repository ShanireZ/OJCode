#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge
{
	int to;
	long long w;
};
vector<Edge> es[10005];
int n, m, b, L = 0x3f3f3f3f, R, ok, cost[10005], in[10005];
long long dis[10005];
queue<int> q;
bool SPFA(int lim)
{
	if (lim < cost[1])
	{
		return false;
	}
	memset(dis, 0x3f, sizeof(dis));
	q.push(1), in[1] = 1, dis[1] = 0;
	while (q.size())
	{
		int f = q.front();
		q.pop(), in[f] = 0;
		for (int i = 0; i < es[f].size(); i++)
		{
			int t = es[f][i].to;
			long long w = es[f][i].w;
			if (cost[t] > lim || w + dis[f] >= dis[t] || w + dis[f] > b)
			{
				continue;
			}
			dis[t] = dis[f] + w;
			if (in[t] == 0)
			{
				q.push(t), in[t] = 1;
			}
		}
	}
	if (dis[n] == 0x3f3f3f3f3f3f3f3f)
	{
		return false;
	}
	return true;
}
int main()
{
	cin >> n >> m >> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		L = min(L, cost[i]), R = max(R, cost[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		es[a].push_back(Edge{b, c}), es[b].push_back(Edge{a, c});
	}
	while (L <= R)
	{
		int mid = (L + R) / 2;
		int ans = SPFA(mid);
		if (ans)
		{
			R = mid - 1, ok = 1;
		}
		else
		{
			L = mid + 1;
		}
	}
	if (ok)
	{
		cout << L << endl;
	}
	else
	{
		cout << "AFK" << endl;
	}
	return 0;
}