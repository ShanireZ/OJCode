#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
double xs[105][105];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n + 1; j++)
		{
			cin >> xs[i][j];
		}
	}
	for (int i = 1; i <= n; i++) //! 枚举每一个当前要消除项
	{
		int pos = i;
		for (int j = i; j <= n; j++) //! 枚举还未被留下的每一行 找到x_i系数最大的行
		{
			if (abs(xs[j][i]) > abs(xs[pos][i]))
			{
				pos = j;
			}
		}
		swap(xs[pos], xs[i]);
		if (xs[i][i] == 0)
		{
			cout << "No Solution" << endl;
			return 0;
		}
		for (int j = n + 1; j >= 1; j--)
		{
			xs[i][j] /= xs[i][i];
		}
		for (int j = 1; j <= n; j++) //! 枚举每一行消除每个式子x_i的系数
		{
			if (i != j)
			{
				for (int k = n + 1; k >= 1; k--) //! 枚举每个式子的每一项
				{
					xs[j][k] -= xs[j][i] * xs[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << fixed << setprecision(2) << xs[i][n + 1] << endl;
	}
	return 0;
}