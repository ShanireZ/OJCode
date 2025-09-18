#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, lmt, ok, cnt, a[20];
void dfs(int step, int delt)
{
	if (step + delt / 3 > lmt)
	{
		return;
	}
	if (delt == 0)
	{
		ok = 1;
		return;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int tmp[20], st[20], p = 0;
			memcpy(st, a, sizeof(a));
			for (int k = i; k <= j; k++)
			{
				tmp[++p] = a[k];
			}
			for (int k = 1; j + k <= n; k++)
			{
				a[i + k - 1] = a[j + k];
				for (int x = i + k, y = 1; y <= p; x++, y++)
				{
					a[x] = tmp[y];
				}
				int dt = 0;
				for (int i = 1; i < n; i++)
				{
					dt += (a[i] + 1 != a[i + 1]);
				}
				dfs(step + 1, dt);
				if (ok)
				{
					return;
				}
			}
			memcpy(a, st, sizeof(st));
		}
	}
}
int main()
{
	cin >> T;
	while (T--)
	{
		lmt = ok = cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i > 1)
			{
				cnt += (a[i] != a[i - 1] + 1);
			}
		}
		while (ok == 0 && lmt < 5)
		{
			dfs(0, cnt);
			lmt++;
		}
		if (ok)
		{
			cout << lmt - 1 << endl;
		}
		else
		{
			cout << "5 or more" << endl;
		}
	}
	return 0;
}