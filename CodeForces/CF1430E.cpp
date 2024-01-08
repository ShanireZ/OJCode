#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long ans;
int n, v[200005], p[200005], last[30];
string s1, s2;
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
	cin >> n >> s1;
	s2 = s1, reverse(s2.begin(), s2.end());
	s1 = '#' + s1, s2 = '#' + s2;
	for (int i = 1; i <= n; i++)
	{
		int id = s1[i] - 'a';
		int pos = s2.find(s1[i], last[id] + 1);
		p[pos] = i, last[id] = pos;
	}
	for (int i = 1; i <= n; i++)
	{
		ans += i - 1 - query(p[i]);
		edit(p[i]);
	}
	cout << ans << endl;
	return 0;
}
// TAG: 树状数组 线段树 逆序对