#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x, res = 0;
		cin >> n >> x;
		res = n + n / x;
		cout << res << endl;
	}
	return 0;
}