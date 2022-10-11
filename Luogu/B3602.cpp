#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MX 300005
struct Path
{
	int to;
	long long d;
	bool operator<(const Path oth) const
	{
		return d > oth.d;
	}
};
int n, m, ok[MX], pre[MX], to[MX], last[MX];
long long dis[MX], d[MX];
priority_queue<Path> q;
int read()
{
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		ans = ans * 10 + ch - '0';
		ch = getchar();
	}
	return ans;
}
void addEdge(int u, int v, int w, int eid)
{
	pre[eid] = last[u], to[eid] = v, d[eid] = w;
	last[u] = eid;
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; i++)
	{
		int u = read(), v = read(), w = read();
		addEdge(u, v, w, i);
	}
	memset(dis, 0x3f, sizeof(dis));
	q.push(Path{1, 0});
	dis[1] = 0;
	while (q.size())
	{
		int now = q.top().to;
		q.pop();
		if (ok[now])
		{
			continue;
		}
		ok[now] = 1;
		for (int i = last[now]; i; i = pre[i])
		{
			int nxt = to[i], w = d[i];
			if (dis[now] + w < dis[nxt])
			{
				dis[nxt] = dis[now] + w;
				q.push(Path{nxt, dis[nxt]});
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (dis[i] == 0x3f3f3f3f3f3f3f3f)
		{
			dis[i] = -1;
		}
		printf("%lld ", dis[i]);
	}
	return 0;
}