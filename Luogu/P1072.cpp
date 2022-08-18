#include <cmath>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
	int r = a % b;
	while (r)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a0, a1, b0, b1, ans = 0;
		cin >> a0 >> a1 >> b0 >> b1;
		for (int x = 1; x * x <= b1; x++)
		{
			if (b1 % x != 0)
			{
				continue;
			}
			if (x % a1 == 0 && gcd(x / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / x) == 1)
			{
				ans++;
			}
			int y = b1 / x;
			if (x != y && y % a1 == 0 && gcd(y / a1, a0 / a1) == 1 && gcd(b1 / b0, b1 / y) == 1)
			{
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}