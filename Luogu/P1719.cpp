#include <iostream>
#include <algorithm>
using namespace std;
int c[150][150]; //每一列的前綴和 c[i][j]表示第i列的前j個元素的前綴和
int main()
{
	int n, maxc = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			c[j][i] = c[j][i - 1] + w;
		}
	}
	for (int i = 1; i <= n; i++) //i~j行間的最大欄位和為i~j行的最大區域
	{
		for (int j = i; j <= n; j++)
		{
			int tot = 0;
			for (int k = 1; k <= n; k++)
			{
				tot = c[k][j] - c[k][i - 1] + max(0, tot);
				maxc = max(maxc, tot);
			}
		}
	}
	cout << maxc;
	return 0;
}