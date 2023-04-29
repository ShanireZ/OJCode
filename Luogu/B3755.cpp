#include <iostream>
using namespace std;
int mp[55][55];
int main()
{
	int n, k, pos = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (i <= k)
		{
			for (int j = i - 1; j - 1 >= 1; j -= 2)
			{
				mp[j][i] = mp[j - 1][i] = ++pos;
			}
			for (int j = i + 1; j + 1 <= n; j += 2)
			{
				mp[j][i] = mp[j + 1][i] = ++pos;
			}
		}
		else
		{
			for (int j = 1; j + 1 <= n; j += 2)
			{
				mp[j][i] = mp[j + 1][i] = ++pos;
			}
		}
	}
	for (int i = 1; i + 1 <= n; i++)
	{
		if (k == n && i + 1 == n)
		{
			break;
		}
		if (mp[n][i] == 0 && mp[n][i + 1] == 0)
		{
			mp[n][i] = mp[n][i + 1] = ++pos;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << mp[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}