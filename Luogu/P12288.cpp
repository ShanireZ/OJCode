#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, a, l[1000005], r[1000005], ok[1000005];
int main()
{
	cin >> n >> a;
	r[0] = a, l[a] = 0, ok[a] = 1;
	cout << 0 << endl;
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		if (ok[a] == 1)
		{
			int x = l[a], y = r[a];
			r[x] = y, l[y] = x;
			if ((a + x) % 2 == 1 && x != 0)
			{
				ans--;
			}
			if ((a + y) % 2 == 1 && y != 0)
			{
				ans--;
			}
			if ((x + y) % 2 == 1 && x != 0 && y != 0)
			{
				ans++;
			}
		}
		int ft = r[0];
		r[0] = a, l[ft] = a;
		l[a] = 0, r[a] = ft;
		if ((a + ft) % 2 == 1 && ft != 0)
		{
			ans++;
		}
		cout << ans << endl;
		ok[a] = 1;
	}
	return 0;
}