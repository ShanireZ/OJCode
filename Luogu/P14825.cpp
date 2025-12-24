#include <algorithm>
#include <iostream>
using namespace std;
int n, cnt, a[1000005], nxt[1000005], pre[1000005];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		nxt[i] = i + 1, pre[i] = i - 1;
	}
	for (int i = 2; i <= n; i++)
	{
		if (pre[i] != 0 && nxt[i] != n + 1 && a[i] >= a[pre[i]] && a[i] <= a[nxt[i]])
		{
			cnt++;
			nxt[pre[i]] = nxt[i];
			pre[nxt[i]] = pre[i];
		}
	}
	cout << n - cnt << endl;
	return 0;
}