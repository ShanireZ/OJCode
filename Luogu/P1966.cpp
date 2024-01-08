#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long ans, mod = 1e8 - 3;
int v[100005], a[100005], b[100005], p[100005], n;
vector<int> all;
int lowbit(int x)
{
	return x & -x;
}
void edit(int x)
{
	while (x <= n)
	{
		v[x]++, x += lowbit(x);
	}
}
int query(int x)
{
	int res = 0;
	while (x > 0)
	{
		res += v[x], x -= lowbit(x);
	}
	return res;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
	}
	all.clear();
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		all.push_back(b[i]);
	}
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	for (int i = 1; i <= n; i++)
	{
		b[i] = lower_bound(all.begin(), all.end(), b[i]) - all.begin() + 1;
		p[b[i]] = i; // 每个数在B中所在的位置
	}
	for (int i = 1; i <= n; i++)
	{
		int pos = p[a[i]];
		b[pos] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + i - 1 - query(b[i])) % mod;
		edit(b[i]);
	}
	cout << ans << endl;
	return 0;
}
// TAG: 树状数组 线段树 逆序对