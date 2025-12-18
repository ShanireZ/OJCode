#include <algorithm>
#include <iostream>
using namespace std;
int dis[35][35], n, ans;
int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> dis[i][j];
		}
	}
	for (int i = 2; i <= n; i++)
	{
		int now = 1e9;
		for (int j = 1; j < i; j++)
		{
			now = min(now, (dis[1][i] + dis[j][i] - dis[1][j]) / 2);
		}
		ans += now;
	}
	cout << ans << endl;
	return 0;
}