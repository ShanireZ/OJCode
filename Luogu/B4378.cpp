#include <algorithm>
#include <iostream>
using namespace std;
int a[105][105], b[105][105], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int p = 1; p <= n / 2; p++)
	{
		for (int j = p; j <= n - p + 1; j++) //! 第p行
		{
			b[p][j] = (p % 2 == 1 ? a[n - j + 1][p] : a[j][n - p + 1]);
		}
		for (int j = p; j <= n - p + 1; j++) //! 第n-p+1列
		{
			b[j][n - p + 1] = (p % 2 == 1 ? a[p][j] : a[n - p + 1][n - j + 1]);
		}
		for (int j = p; j <= n - p + 1; j++) //! 第n-p+1行
		{
			b[n - p + 1][j] = (p % 2 == 1 ? a[n - j + 1][n - p + 1] : a[j][p]);
		}
		for (int j = p; j <= n - p + 1; j++) //! 第p列
		{
			b[j][p] = (p % 2 == 1 ? a[n - p + 1][j] : a[p][n - j + 1]);
		}
	}
	if (n % 2 == 1)
	{
		b[n / 2 + 1][n / 2 + 1] = a[n / 2 + 1][n / 2 + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}