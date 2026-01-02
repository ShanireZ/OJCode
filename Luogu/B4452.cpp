#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	string s;
	int p, v;
};
Node ns[1005];
int m, n, pos;
string b[1005];
bool cmp(Node a, Node b)
{
	if (a.v == b.v)
	{
		if (a.p == b.p)
		{
			return a.s < b.s;
		}
		return a.p < b.p;
	}
	return a.v < b.v;
}
int main()
{
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].s >> ns[i].p >> ns[i].v;
	}
	sort(ns + 1, ns + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		if (m >= ns[i].p)
		{
			b[++pos] = ns[i].s;
			m -= ns[i].p;
		}
	}
	sort(b + 1, b + 1 + pos);
	for (int i = 1; i <= pos; i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}