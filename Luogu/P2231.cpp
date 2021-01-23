#include <iostream>
#include <algorithm>
using namespace std;
int v[405][405];
int sum[405][405];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> v[i][j];
			sum[i][j] = sum[i][j - 1] + v[i][j];
		}
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int s = 0;
			for (int a = 0; a <= k; a++) //上
			{
				if (i - a < 1)
				{
					break;
				}
				int st = max(j - (k - a) - 1, 0);
				int ed = min(j + (k - a), n);
				s += sum[i - a][ed] - sum[i - a][st];
			}
			for (int a = 1; a <= k; a++) //下
			{
				if (i + a > n)
				{
					break;
				}
				int st = max(j - (k - a) - 1, 0);
				int ed = min(j + (k - a), n);
				s += sum[i + a][ed] - sum[i + a][st];
			}
			maxn = max(maxn, s);
		}
	}
	cout << maxn;
	return 0;
}