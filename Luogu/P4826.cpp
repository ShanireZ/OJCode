#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[2005], g[2005];
struct Node
{
	int u, v, w;
};
bool cmp(Node a, Node b)
{
	return a.w > b.w;
}
vector<Node> ns;
int dfn(int x)
{
	if (g[x] != x)
	{
		g[x] = dfn(g[x]);
	}
	return g[x];
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for (int j = 1; j < i; j++)
		{
			Node x;
			x.w = a[i] ^ a[j];
			x.u = i, x.v = j;
			ns.push_back(x);
		}
		g[i] = i;
	}
	sort(ns.begin(), ns.end(), cmp);
	long long ans = 0, cnt = 0;
	for (int i = 0; i < ns.size() && cnt < n - 1; i++)
	{
		int ga = dfn(ns[i].u);
		int gb = dfn(ns[i].v);
		if (ga != gb)
		{
			g[ga] = gb;
			ans += ns[i].w;
			cnt++;
		}
	}
	cout << ans;
	return 0;
}