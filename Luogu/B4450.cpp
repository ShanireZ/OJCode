#include <algorithm>
#include <iostream>
using namespace std;
int m, n, res, mn[100005];
int main()
{
	cin >> m >> n;
	fill(mn + 1, mn + 1 + m, 1e6);
	for (int i = 1; i <= n; i++)
	{
		int k, p;
		cin >> k >> p;
		mn[k] = min(mn[k], p);
	}
	for (int i = 1; i <= m; i++)
	{
		res += mn[i];
	}
	cout << res << endl;
	return 0;
}