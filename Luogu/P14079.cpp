#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	long long n, p, q;
	cin >> n >> p >> q;
	while (n--)
	{
		long long a, b;
		cin >> a >> b;
		if (a == b)
		{
			cout << 0 << endl;
		}
		else if (a == 1 || b == 1) //! 只能选择互质
		{
			cout << p << endl;
		}
		else if (__gcd(a, b) == 1) //! 还可通过a*b中转
		{
			cout << min(p, q + q) << endl;
		}
		else //! 还可通过1中转
		{
			cout << min(p + p, q) << endl;
		}
	}
	return 0;
}
