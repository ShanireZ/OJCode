#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int v, id;
	bool operator<(const Node &oth) const
	{
		if (v == oth.v)
		{
			return id < oth.id;
		}
		return v > oth.v;
	}
};
Node ns[500005];
int n, m, k, now;
int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].v;
		ns[i].id = i;
	}
	sort(ns + 1, ns + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (ns[i].id == k)
		{
			now = i;
			break;
		}
	}
	for (int i = now - 1; i >= 1; i--)
	{
		m -= (ns[i].v - ns[now].v) + (ns[i].id < ns[now].id);
		if (ns[1].v == ns[i].v || m < 0)
		{
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << now << endl;
	return 0;
}