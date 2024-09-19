#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int t, d, t1, d1, t2, d2, ans = 1e9;
	cin >> t >> d >> t1 >> d1 >> t2 >> d2;
	if (d <= d1)
	{
		ans = min(ans, t1 - t);
	}
	if (d <= d2)
	{
		ans = min(ans, t2 - t);
	}
	cout << (ans == 1e9 ? -1 : max(0, ans)) << endl;
	return 0;
}