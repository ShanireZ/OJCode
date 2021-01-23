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
	int minc = 0x3f3f3f3f;
	int tot1 = 0; //改了多少格子变白色
	for (int i = 1; i <= n - 2; i++)
	{
		tot1 += m - color[i][0];
		int tot2 = tot1; //改了多少格子变蓝色和白色
		for (int j = i + 1; j <= n - 1; j++)
		{
			tot2 += m - color[j][1];
			int tot3 = tot2; //改了多少格子变红色 蓝色 白色
			for (int k = j + 1; k <= n; k++)
			{
				tot3 += m - color[k][2];
			}
			minc = min(minc, tot3);
		}
	}
	cout << minc;
	return 0;
}