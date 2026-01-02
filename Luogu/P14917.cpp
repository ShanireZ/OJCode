#include <algorithm>
#include <iostream>
using namespace std;
int ans, now, n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		if (a <= ans)
		{
			continue;
		}
		if (now == 0)
		{
			now = a;
		}
		else if (now == a)
		{
			now = 0;
		}
		else if (a > ans && a < now)
		{
			ans = a;
		}
		else
		{
			ans = now;
			now = a;
		}
	}
	cout << ans << endl;
	return 0;
}