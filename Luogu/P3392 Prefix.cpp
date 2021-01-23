#include <iostream>
using namespace std;
int color[55][3]; //!0白 1蓝 2红
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'W')
			{
				color[i][0]++;
			}
			else if (ch == 'B')
			{
				color[i][1]++;
			}
			else
			{
				color[i][2]++;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			color[i][j] += color[i - 1][j];
		}
	}
	int minc = 3000;
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 1; j <= n - 1; j++)
		{
			int w = color[i][1] + color[i][2];
			int b = (color[j][0] - color[i][0]) + (color[j][2] - color[i][2]);
			int r = (color[n][0] - color[j][0]) + (color[n][1] - color[j][1]);
			minc = min(minc, w + b + r);
		}
	}
	cout << minc;
	return 0;
}