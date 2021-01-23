#include <iostream>
#include <algorithm>
using namespace std;
int cnt[1005][1005];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j <= x2; j++)
		{
			cnt[j][y1]++;
			cnt[j][y2 + 1]--;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int num = 0;
		for (int j = 1; j <= n; j++)
		{
			num += cnt[i][j];
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}