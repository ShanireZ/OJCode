#include <algorithm>
#include <iostream>
using namespace std;
int tz[10], pho[25][5], n, maxt, mint;
int ps[50][5] = {{0}, {1, 2, 3}, {1, 3, 5}, {1, 5, 6}, {1, 6, 2}, {2, 3, 1}, {2, 1, 6}, {2, 6, 4}, {2, 4, 3}, {3, 1, 2}, {3, 2, 4}, {3, 4, 5}, {3, 5, 1}, {4, 3, 2}, {4, 2, 6}, {4, 6, 5}, {4, 5, 3}, {5, 1, 3}, {5, 3, 4}, {5, 4, 6}, {5, 6, 1}, {6, 1, 5}, {6, 5, 4}, {6, 4, 2}, {6, 2, 1}};
bool check(int t, int pos)
{
	return (pho[t][0] == tz[ps[pos][0]] && pho[t][1] == tz[ps[pos][1]] && pho[t][2] == tz[ps[pos][2]]);
}
void dfs(int step, int tot)
{
	if (step == 7)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) // 枚举每张照片
		{
			for (int j = 1; j <= 24; j++) // 枚举所有拍摄角度
			{
				if (check(i, j))
				{
					cnt++;
					break;
				}
			}
		}
		if (cnt == n)
		{
			maxt = max(maxt, tot), mint = min(mint, tot);
		}
		return;
	}
	for (int i = 1; i <= 6; i++)
	{
		tz[step] = i;
		dfs(step + 1, tot + i);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> pho[i][0] >> pho[i][1] >> pho[i][2];
	}
	mint = 0x3f3f3f3f, maxt = 0;
	dfs(1, 0);
	cout << mint << " " << maxt << endl;
	return 0;
}