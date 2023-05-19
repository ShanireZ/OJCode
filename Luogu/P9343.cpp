#include <iostream>
using namespace std;
int vis[200005];
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, cnt = 0, ans = -1, save = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			int a, x;
			cin >> a >> x;
			if (a == 1)
			{
				if (save == 0 && vis[x] == 0)
				{
					vis[x] = 1, cnt++;
				}
				else if (save == x)
				{
					cnt = n;
				}
			}
			else
			{
				cnt = n - 1;
				if ((save != 0 && save != x) || vis[x])
				{
					cnt++;
				}
				save = x;
			}
			if (cnt == n && ans == -1)
			{
				ans = i;
			}
		}
		cout << ans << "\n";
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
		}
	}
	return 0;
}