#include <iostream>
#include <string>
using namespace std;
int n, m, x, y, cnt[55][55], pos[55][55];
string s;
int main()
{
	cin >> n >> m >> y >> x >> s;
	s.insert(0, "x");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			pos[i][j] = 2, cnt[i][j] = 1;
		}
	}
	pos[x][y] = 1, cnt[x][y] = 0;
	for (int k = 1; k < m; k++)
	{
		if (s[k] == 'N')
		{
			x++;
		}
		else if (s[k] == 'S')
		{
			x--;
		}
		else if (s[k] == 'E')
		{
			y++;
		}
		else
		{
			y--;
		}
		pos[x][y] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cnt[i][j] += pos[i][j];
				pos[i][j]++;
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << cnt[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}