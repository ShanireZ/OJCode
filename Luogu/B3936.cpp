#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
	int x, y, z, id;
};
Node ns[1005];
long long h[1005], ans[1005], add[1005][1005];
bool cmpx(Node a, Node b)
{
	return a.x < b.x;
}
int main()
{
	int n, m, q, now = 0;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> add[i][j];
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> ns[i].x >> ns[i].y >> ns[i].z;
		ns[i].id = i;
	}
	sort(ns + 1, ns + q + 1, cmpx);
	for (int i = 1; i <= q; i++)
	{
		while (now < ns[i].x)
		{
			now++;
			for (int j = 1; j <= n; j++)
			{
				h[j] += add[now][j];
			}
		}
		ans[ns[i].id] = h[ns[i].y] - h[ns[i].z];
	}
	for (int i = 1; i <= q; i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}