#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int n, a[1000005], v[1000005], last[30];
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
	cin >> n >> s1 >> s2;
	s1 = '#' + s1, s2 = '#' + s2;
	for (int i = 1; i <= n; i++)
	{
		int id = s1[i] - 'A';
		int p = s2.find(s1[i], last[id] + 1);
		last[id] = p, a[p] = i;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += i - 1 - query(a[i]);
		edit(a[i]);
	}
	cout << ans << endl;
	return 0;
}
// TAG: 树状数组 线段树 逆序对