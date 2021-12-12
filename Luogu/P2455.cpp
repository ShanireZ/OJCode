#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
// 2
// 0 2 3
// 0 0 0
double f[55][55], ans[55];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			cin >> f[i][j];
		}
	}
	int now = 1;
	for (int j = 1; j <= n; j++) //查找当前项最大系数 存到第now行
	{
		int pos = now;
		for (int i = now + 1; i <= n; i++)
		{
			if (fabs(f[i][j]) > fabs(f[pos][j]))
			{
				pos = i;
			}
		}
		if (f[pos][j] == 0)
		{
			continue;
		}
		for (int k = 1; k <= n + 1; k++) //将第j项最大系数的式子放在第now行
		{
			swap(f[pos][k], f[now][k]);
		}
		for (int i = 1; i <= n; i++) //逐行消元
		{
			if (i == now)
			{
				continue;
			}
			double x = f[i][j] / f[now][j]; //当前行的第j项是第now行几倍
			for (int k = j; k <= n + 1; k++)
			{
				f[i][k] -= x * f[now][k];
			}
		}
		now++;
	}
	for (int i = 1; i <= n; i++)
	{
		ans[i] = 100000000;
	}
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		for (int j = 1; j <= n; j++)
		{
			if (fabs(f[i][j]) > 1e-6)
			{
				p = j;
				break;
			}
		}
		if (p == 0 && f[i][n + 1] != 0)
		{
			cout << -1 << endl;
			return 0;
		}
		if (p != 0)
		{
			ans[p] = f[i][n + 1] / f[i][p];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 100000000)
		{
			cout << 0 << endl;
			return 0;
		}
		if (fabs(ans[i]) < 1e-6)
		{
			ans[i] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "x" << i << "=";
		cout << fixed << setprecision(2) << ans[i] << endl;
	}
	return 0;
}