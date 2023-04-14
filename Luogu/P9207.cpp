#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a[505], b[505];
int main()
{
	int n, k, sza = 0, szb = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		(x >= 0) ? (a[++sza] = x) : (b[++szb] = x);
	}
	sort(a + 1, a + 1 + sza), sort(b + 1, b + 1 + szb, greater<int>());
	int trig = 1, tot = 0, pa = 1, pb = 1, maxv = (int)pow(2, k - 1) - 1, minv = -(int)pow(2, k - 1);
	while (trig)
	{
		trig = 0;
		while (pb <= szb && tot + b[pb] >= minv)
		{
			tot += b[pb++];
			trig = 1;
		}
		while (pa <= sza && tot + a[pa] <= maxv)
		{
			tot += a[pa++];
			trig = 1;
		}
	}
	cout << pa + pb - 2 << "\n";
	return 0;
}