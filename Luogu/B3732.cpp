#include <algorithm>
#include <iostream>
using namespace std;
int t[1005];
int main()
{
	int n, r, ans = 0, now = 0;
	cin >> n >> r;
	for (int i = 1; i <= n; i++)
	{
		t[i] = (r % 100) + 1;
		r = (r * 6807 + 2831) % 201701;
	}
	sort(t + 1, t + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		now += t[i];
		ans += now;
	}
	cout << ans << "\n";
	return 0;
}