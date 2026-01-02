#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, pre[100005], nxt[100005], p[100005][2];
void del(int x)
{
	nxt[pre[x]] = nxt[x], pre[nxt[x]] = pre[x];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		p[a][0] == 0 ? p[a][0] = i : p[a][1] = i;
		pre[i] = i - 1, nxt[i] = i + 1;
	}
	nxt[0] = 1, pre[n + 1] = n;
	for (int i = 1, lst = 0; i <= 100000; i++)
	{
		if (p[i][0] == 0)
		{
			continue;
		}
		int p0 = p[i][0], p1 = p[i][1];
		while (pre[p1] != p0 && ++lst != i)
		{
			if (p[lst][0] == 0)
			{
				continue;
			}
			del(p[lst][0]), del(p[lst][1]), ans = lst;
		}
		if (pre[p1] != p0)
		{
			del(p0), del(p1), ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}