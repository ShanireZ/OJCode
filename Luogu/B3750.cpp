#include <iostream>
using namespace std;
int vis[10005];
int main()
{
	int m, n;
	cin >> m >> n;
	vis[0] = vis[1] = 1;
	for (int i = 2; i <= 100; i++)
	{
		if (vis[i] == 0)
		{
			for (int j = 2; i * j < 10000; j++)
			{
				vis[i * j] = 1;
			}
		}
	}
	for (int i = m; i <= n; i++)
	{
		int x = i, ok = 1;
		while (x && ok)
		{
			if (vis[x] == 1)
			{
				ok = 0;
				break;
			}
			x /= 10;
		}
		if (ok)
		{
			cout << i << "\n";
		}
	}
	return 0;
}