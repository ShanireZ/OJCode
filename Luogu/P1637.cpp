#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[30005];
int n, num, a[30005];
long long ans;
int lowbit(int x)
{
	return x & -x;
}
void edit(int p, int x)
{
	for (int i = p; i <= n; i += lowbit(i))
	{
		v[i].push_back(x);
	}
}
long long query(int p, int x, int op) // 1-p中:op=1小于x的个数,op=2大于x的个数
{
	long long res = 0;
	for (int i = p; i > 0; i -= lowbit(i))
	{
		if (op == 1)
		{
			res += lower_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
		}
		else
		{
			res += v[i].end() - upper_bound(v[i].begin(), v[i].end(), x);
		}
	}
	return res;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		edit(i, a[i]);
		sort(v[i].begin(), v[i].end());
	}
	for (int i = 2; i < n; i++)
	{
		ans += query(i - 1, a[i], 1) * (query(n, a[i], 2) - query(i, a[i], 2));
	}
	cout << ans << endl;
	return 0;
}
// TAG: 归并树 树状数组 线段树