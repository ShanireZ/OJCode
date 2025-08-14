#include <algorithm>
#include <iostream>
using namespace std;
int p[100005], n, k, q, l, r;
int main()
{
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
	{
		cin >> p[i];
	}
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		if (l > r)
		{
			swap(l, r);
		}
		if (l == r)
		{
			cout << 1 << "\n";
			continue;
		}
		int st = upper_bound(p, p + k + 1, l) - p;
		int ed = upper_bound(p, p + k + 1, r) - p;
		if (st == ed)
		{
			cout << 2 << "\n";
			continue;
		}
		int ex = (l == p[st - 1]) + (r == p[ed] - 1);
		cout << 2 + ex + ed - st - 1 << "\n";
	}
	return 0;
}