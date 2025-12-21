#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int v[55][55], n, k;
string s;
int main()
{
	cin >> n >> k >> s;
	memset(v, -1, sizeof(v));
	int x = n / 2 + 1, y = n / 2 + 1;
	for (char ch : s)
	{
		if (ch == 'L')
		{
			y = (y == 1 ? 1 : y - 1);
		}
		else if (ch == 'R')
		{
			y = (y == n ? n : y + 1);
		}
		else if (ch == 'U')
		{
			x = (x == 1 ? 1 : x - 1);
		}
		else if (ch == 'D')
		{
			x = (x == n ? n : x + 1);
		}
		else
		{
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; i + j < k; j++)
				{
					int nx1 = max(x - i, 1), ny1 = max(y - j, 1);
					int nx2 = min(x + i, n), ny2 = min(y + j, n);
					v[nx1][ny1] = v[nx2][ny2] = v[nx1][ny2] = v[nx2][ny1] = ch - 'A';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << (v[i][j] == -1 ? '.' : char(v[i][j] + 'A'));
		}
		cout << endl;
	}
	return 0;
}