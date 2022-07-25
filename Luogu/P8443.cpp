#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long l, r, x;
		cin >> l >> r >> x;
		if (l / x == r / x)
		{
			cout << l / x << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}
	return 0;
}