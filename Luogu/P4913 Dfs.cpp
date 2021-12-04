#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
	int lc, rc, dep;
};
Node ns[1000005];
int maxdp;
void dfs(int now, int deep)
{
	ns[now].dep = deep;
	maxdp = max(deep, maxdp);
	if (ns[now].lc)
	{
		dfs(ns[now].lc, deep + 1);
	}
	if (ns[now].rc)
	{
		dfs(ns[now].rc, deep + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ns[i].lc >> ns[i].rc;
	}
	dfs(1, 1);
	cout << maxdp << endl;
	return 0;
}