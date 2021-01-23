#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int mp[1005][1005]; //差分-----原数
int a[1005][1005];	//前缀和---左上区域和
int main()
{
	int n, m, c;
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> mp[i][j];
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + mp[i][j];
		}
	}
	int maxc = INT_MIN, maxx = 1, maxy = 1;
	for (int i = c; i <= n; i++) //右下坐标
	{
		for (int j = c; j <= m; j++)
		{
			int tot = a[i][j] - a[i - c][j] - a[i][j - c] + a[i - c][j - c];
			if (tot > maxc)
			{
				maxc = tot;
				maxx = i - c + 1, maxy = j - c + 1;
			}
		}
	}
	cout << maxx << " " << maxy;
	return 0;
}