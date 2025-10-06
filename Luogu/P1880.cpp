#include <algorithm>
#include <iostream>
using namespace std;
int qz[205], m[205], mx[205][205], mn[205][205], n;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
		qz[i] = qz[i - 1] + m[i];
	}
	for (int i = n + 1; i <= n + n; i++)
	{
		m[i] = m[i - n];
		qz[i] = qz[i - 1] + m[i];
	}
	for (int len = 2; len <= n; len++)
	{
		for (int st = 1, ed = len; ed <= n + n; st++, ed++)
		{
			mx[st][ed] = 0, mn[st][ed] = 1e9;
			for (int i = st; i < ed; i++)
			{
				mx[st][ed] = max(mx[st][ed], mx[st][i] + mx[i + 1][ed] + qz[ed] - qz[st - 1]);
				mn[st][ed] = min(mn[st][ed], mn[st][i] + mn[i + 1][ed] + qz[ed] - qz[st - 1]);
			}
		}
	}
	int ansmx = 0, ansmn = 1e9;
	for (int i = 1; i <= n; i++)
	{
		ansmx = max(ansmx, mx[i][i + n - 1]);
		ansmn = min(ansmn, mn[i][i + n - 1]);
	}
	cout << ansmn << endl
		 << ansmx << endl;
	return 0;
}