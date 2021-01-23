#include <iostream>
#include <algorithm>
using namespace std;
int c[100005]; //次数差分
struct Road
{
	long long a, b, c;
};
Road rs[100005];
int main()
{
	int n, m, pre, cur;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> cur;
		if (i > 1)
		{
			int x = cur, y = pre;
			if (x > y)
			{
				swap(x, y);
			}
			c[x]++;
			c[y]--;
		}
		pre = cur;
	}
	long long tot = 0, cnt = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> rs[i].a >> rs[i].b >> rs[i].c;
		cnt += c[i];
		tot += min(rs[i].a * cnt, rs[i].c + rs[i].b * cnt);
	}
	cout << tot;
	return 0;
}