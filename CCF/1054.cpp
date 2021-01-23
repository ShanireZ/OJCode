#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, i, j, x, y;
	cin >> n >> m;
	char a[n][m];
	int b[n][m];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			if(a[i][j] == '*')
			{
				cout << '*';
			}else
			{
				for(x = i - 1; x <= i + 1; x++)
				{
					for(y = j - 1; y <= j + 1; y++)
					{
						if(x < 0 || x == n || y < 0 || y == m)
						{
							continue;
						}else if(a[x][y] == '*')
						{
							b[i][j]++;
						}
					}
				}
				cout << b[i][j];
			}
		}
		cout << endl;
	}
	return 0;
}
