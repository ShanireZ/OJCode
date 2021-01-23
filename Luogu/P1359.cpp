#include <iostream>
#include <algorithm>
using namespace std;
int m[205][205];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			m[i][j] = 1e7;
			if (i == j)
			{
				m[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> m[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (m[j][i] != 1e7 && m[i][k] != 1e7)
				{
					m[j][k] = min(m[j][k], m[j][i] + m[i][k]);
				}
			}
		}
	}
	cout << m[1][n];
	return 0;
}