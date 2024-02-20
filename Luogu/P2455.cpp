#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double f[55][55];
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
	for (int j = 1, now = 1; j <= n; j++) // 查找当前项最大系数 存到第now行
	{
		int mpos = now;
		for (int i = now; i <= n; i++)
		{
			if (abs(f[i][j]) > abs(f[mpos][j]))
			{
				mpos = i;
			}
		}
		if (abs(f[mpos][j]) < 1e-6)
		{
			continue;
		}
		swap(f[now], f[mpos]);
		for (int i = n + 1; i >= j; i--)
		{
			f[now][i] /= f[now][j];
		}
		for (int i = 1; i <= n; i++) // 逐行消元
		{
			if (i == now)
			{
				continue;
			}
			for (int k = n + 1; k >= j; k--)
			{
				f[i][k] -= f[i][j] * f[now][k];
			}
		}
		now++;
	}
	int sta = 1;
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		for (int j = 1; j <= n; j++)
		{
			if (abs(f[i][j]) > 1e-6)
			{
				p = j;
				break;
			}
		}
		if (p == 0)
		{
			if (abs(f[i][n + 1]) > 1e-6)
			{
				cout << -1 << endl;
				return 0;
			}
			else
			{
				sta = 0;
			}
		}
	}
	if (sta == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "x" << i << "=";
		cout << fixed << setprecision(2) << f[i][n + 1] << endl;
	}
	return 0;
}