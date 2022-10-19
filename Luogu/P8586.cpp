#include <iostream>
using namespace std;
int tot[300005];
int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int d, m;
		cin >> d >> m;
		tot[d] += m;
	}
	long long ans = 0, pre = 0;
	for(int i = 1; i <= 300000; i++)
	{
		int now = k;
		if(now >= pre)
		{
			ans += pre;
			now -= pre;
			pre = 0;
		}
		else
		{
			ans += now;
			pre = tot[i];
			continue;
		}
		if(now >= tot[i])
		{
			ans += tot[i];
		}
		else
		{
			ans += now, pre = tot[i] - now;
		}
	}
	cout << ans << endl;
	return 0;
} 