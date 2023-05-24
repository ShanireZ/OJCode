#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		int minn = 10, tot = 8;
		while (n)
		{
			int r = n % 10;
			tot += r, minn = min(minn, r);
			n /= 10;
		}
		cout << tot + (minn == 0) << "\n";
	}
	return 0;
}