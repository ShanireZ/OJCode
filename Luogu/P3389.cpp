#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f[105][105];
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
	for (int j = 1; j <= n; j++) //列举每一项
	{
		int pos = j;					 //第j项系数最大行
		for (int i = j + 1; i <= n; i++) //列举当前行下方每一行
		{
			if (fabs(f[i][j]) > fabs(f[pos][j]))
			{
				pos = i;
			}
		}
		for (int i = 1; i <= n + 1; i++) //交换当前行和最大行
		{
			swap(f[pos][i], f[j][i]);
		}
		if (f[j][j] == 0) //第j项最大系数为0 说明该项所有系数都是0 有无限多解
		{
			cout << "No Solution" << endl;
			return 0;
		}
		for (int i = 1; i <= n; i++) //第j项消元
		{
			if (i == j)
			{
				continue;
			}
			double x = f[i][j] / f[j][j];
			for (int k = j; k <= n + 1; k++)
			{
				f[i][k] -= x * f[j][k];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << fixed << setprecision(2) << f[i][n + 1] / f[i][i] << endl;
	}
	return 0;
}