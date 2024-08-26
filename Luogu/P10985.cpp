#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n, ans = 0;
	cin >> n;
	while (n)
	{
		int tot = 0, x = n;
		while (x)
		{
			tot += x % 10;
			x /= 10;
		}
		n -= tot, ans++;
	}
	cout << ans << endl;
	return 0;
}