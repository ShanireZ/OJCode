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
	for (int x = 1; x <= n; x++) //! 枚舉每個x的係數
	{
		int pos = x;
		for (int i = x; i <= n; i++) //! 枚舉每個方程 找到第x項係數最大的那個方程
		{
			if (abs(xs[i][x]) > abs(xs[pos][x]))
			{
				pos = i;
			}
		}
		swap(xs[x], xs[pos]); //! 交換兩個方程
		if (xs[x][x] == 0)
		{
			cout << "No Solution" << endl;
			return 0;
		}
		for (int j = n + 1; j >= x; j--)
		{
			xs[x][j] /= xs[x][x];
		}
		for (int i = 1; i <= n; i++) //! 枚舉每個方程的每一項
		{
			if (i == x)
			{
				continue;
			}
			for (int j = n + 1; j >= x; j--)
			{
				xs[i][j] -= xs[i][x] * xs[x][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << fixed << setprecision(2) << xs[i][n + 1] << endl;
	}
	return 0;
}