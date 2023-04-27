#include <algorithm>
#include <iostream>
using namespace std;
int m[10][10], all[20], pos, ans;
int main()
{
	int n, x = 4, y = 4;
	cin >> n;
	while (n)
	{
		m[x][y] = n % 2, n /= 2;
		y == 1 ? x--, y = 4 : y--;
	}
	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (m[i][j] == 1)
			{
				ans -= i;
				all[++pos] = j;
			}
		}
	}
	sort(all + 1, all + 1 + pos);
	for (int j = 4; j >= 1; j--)
	{
		for (int i = 3; i <= 4; i++)
		{
			if (m[i][j] == 0)
			{
				ans += i + abs(all[pos--] - j);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}