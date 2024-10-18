#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Path
{
	long long v, w, t;
	bool operator<(const Path &oth) const
	{
		if (w == oth.w) // 把同一个点w相同的路径放一起,方便统计次数
		{
			return v > oth.v;
		}
		return w > oth.w;
	}
};
priority_queue<Path> q;
vector<pair<int, int>> pf[1005];
long long t[1005], dis[1005], n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		q.emplace(Path{i, x, 1});
	}
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		pf[a].emplace_back(make_pair(b, c));
		if (a != b) // 坑点
		{
			pf[b].emplace_back(make_pair(a, c));
		}
	}
	fill(dis, dis + n, 0x3f3f3f3f);
	while (q.size())
	{
		long long now = q.top().v, w = q.top().w, tz = q.top().t;
		q.pop();
		if (dis[now] != 0x3f3f3f3f)
		{
			continue;
		}
		dis[now] = w, t[now] = tz;
		while (q.size() && q.top().v == now && q.top().w == w)
		{
			t[now] += q.top().t;
			q.pop();
		}
		for (auto p : pf[now])
		{
			int oth = p.first, nxt = p.second;
			if (dis[now] + dis[oth] <= dis[nxt])
			{
				q.emplace(Path{nxt, dis[now] + dis[oth], t[now] * t[oth]});
			}
		}
	}
	cout << dis[0] << ' ' << t[0] << endl;
	return 0;
}