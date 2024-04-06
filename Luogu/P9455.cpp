#include <algorithm>
#include <iostream>
using namespace std;
int n, p[500005], k[500005];
int main()
{
	// 本题简单在位置单调递增已经有序
	// 所以如果能从1到n 则一定能从1-2-3-4-...-n
	cin >> n >> p[1] >> k[1];
	int now = p[1] + k[1], delta = 0;
	for (int i = 2; i <= n; i++)
	{
		cin >> p[i] >> k[i];
		if (now < p[i]) // 差多少补多少
		{
			delta += p[i] - now;
		}
		now = max(now, p[i] + k[i] + delta);
	}
	cout << delta << endl;
	return 0;
}