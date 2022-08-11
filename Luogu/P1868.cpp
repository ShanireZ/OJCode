#include <algorithm>
#include <iostream>
using namespace std;
int dp[3000005]; // dp[i] 前i块草地可同时选择的最大牧草数量
struct Line
{
	int l, r;
	bool operator<(const Line oth) const
	{
		return r < oth.r;
	}
};
Line ls[150005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ls[i].l >> ls[i].r;
	}
	sort(ls + 1, ls + 1 + n);
	int pos = 1, maxc = 0;
	for (int i = 1; i <= 3000000 && pos <= n; i++)
	{
		while (ls[pos].r == i) // 如果当前位置是一个区间的结束
		{
			maxc = max(maxc, dp[ls[pos].l - 1] + ls[pos].r - ls[pos].l + 1);
			pos++;
		}
		dp[i] = maxc;
	}
	cout << maxc << endl;
	return 0;
}