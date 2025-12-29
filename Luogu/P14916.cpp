#include <algorithm>
#include <iostream>
using namespace std;
int k, q, n[100005], zx = 1e6;
int toA(int pos)
{
	int step = 0;
	while (pos != 1)
	{
		step++, pos /= 2;
	}
	return step;
}
int toB(int pos, int tree)
{
	int step = 0;
	while (pos <= n[tree] / 2)
	{
		step++;
		pos = (pos * 2 + 1 <= n[tree] ? pos * 2 + 1 : pos * 2);
	}
	return step;
}
int main()
{
	cin >> k >> q;
	for (int i = 1; i <= k; i++)
	{
		cin >> n[i];
		zx = min(zx, toA(n[i] / 2 + 1));
	}
	while (q--)
	{
		int s, u, t, v, ans = 1e9, res = 0;
		cin >> s >> u >> t >> v;
		if (s > t)
		{
			swap(s, t), swap(u, v);
		}
		if (s == t)
		{
			int nu = u, nv = v;
			while (nu != nv)
			{
				res++;
				nu > nv ? nu /= 2 : nv /= 2;
			}
			ans = min(ans, res); // u -> LCA -> v
		}
		res = toA(u) + (k % 2 == 0 && (t - s) % 2 == 1) * zx + toA(v);
		ans = min(ans, res); // u -> s的A -> 另一树B -> ... -> t树A -> v
		res = toA(u) + (k % 2 == 0 && (t - s) % 2 == 0) * zx + toB(v, t);
		ans = min(ans, res); // u -> s的A -> 另一树B -> ... -> t树B -> v
		res = toB(u, s) + (k % 2 == 0 && (t - s) % 2 == 0) * zx + toA(v);
		ans = min(ans, res); // u -> s的B -> 另一树A -> ... -> t树A -> v
		res = toB(u, s) + (k % 2 == 0 && (t - s) % 2 == 1) * zx + toB(v, t);
		ans = min(ans, res); // u -> s的B -> 另一树A -> ... -> t树B -> v
		cout << ans << endl;
	}
	return 0;
}