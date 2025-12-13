#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int d, v, id;
	string s;
	bool operator<(const Node &oth) const
	{
		if (d == oth.d)
		{
			return v > oth.v;
		}
		return d < oth.d;
	}
};
Node ns[200005];
int trie[1000005][26], root = 1, pos = 1, n, m;
long long f[1000005], ans[200005];
void init(int i)
{
	int now = root;
	for (char ch : ns[i].s)
	{
		int x = ch - 'a';
		if (trie[now][x] == 0)
		{
			trie[now][x] = ++pos;
		}
		now = trie[now][x];
		f[now] += ns[i].v;
	}
}
long long query(int i)
{
	int now = root;
	for (char ch : ns[i].s)
	{
		int x = ch - 'a';
		if (trie[now][x] == 0)
		{
			return 0;
		}
		now = trie[now][x];
	}
	return f[now];
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].d >> ns[i].v >> ns[i].s;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> ns[i + n].d >> ns[i + n].s;
		ns[i + n].v = -1, ns[i + n].id = i;
	}
	sort(ns + 1, ns + n + m + 1);
	for (int i = 1; i <= n + m; i++)
	{
		if (ns[i].v == -1)
		{
			ans[ns[i].id] = query(i);
		}
		else
		{
			init(i);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}