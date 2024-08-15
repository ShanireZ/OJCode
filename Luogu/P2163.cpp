#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	int x, y;
	bool operator<(const Node &oth) const
	{
		return x < oth.x;
	}
};
Node ns[500005];
struct Area
{
	int a, b, c, d;
};
Area as[500005];
int n, m, pos, ans[500005], ls[3000005], ts[3000005];
vector<int> ids[3000005];
void edit(int x)
{
	while (x <= pos)
	{
		ts[x]++;
		x += (x & -x);
	}
}
int query(int x)
{
	int res = 0;
	while (x)
	{
		res += ts[x];
		x -= (x & -x);
	}
	return res;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		x++, y++;
		ls[++pos] = x, ls[++pos] = y, ns[i] = Node{x, y};
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a++, b++, c++, d++;
		ls[++pos] = a - 1, ls[++pos] = b - 1, ls[++pos] = c, ls[++pos] = d, as[i] = Area{a - 1, b - 1, c, d};
	}
	sort(ls + 1, ls + pos + 1);
	pos = unique(ls + 1, ls + pos + 1) - ls - 1;
	for (int i = 1; i <= n; i++)
	{
		ns[i].x = lower_bound(ls + 1, ls + pos + 1, ns[i].x) - ls;
		ns[i].y = lower_bound(ls + 1, ls + pos + 1, ns[i].y) - ls;
	}
	for (int i = 1; i <= m; i++)
	{
		as[i].a = lower_bound(ls + 1, ls + pos + 1, as[i].a) - ls;
		as[i].b = lower_bound(ls + 1, ls + pos + 1, as[i].b) - ls;
		as[i].c = lower_bound(ls + 1, ls + pos + 1, as[i].c) - ls;
		as[i].d = lower_bound(ls + 1, ls + pos + 1, as[i].d) - ls;
		ids[as[i].a].emplace_back(i), ids[as[i].c].emplace_back(i);
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1, now = 1; i <= pos; i++)
	{
		while (now <= n && ns[now].x == i)
		{
			edit(ns[now].y);
			now++;
		}
		for (int id : ids[i])
		{
			ans[id] = query(as[id].d) - query(as[id].b) - ans[id];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}