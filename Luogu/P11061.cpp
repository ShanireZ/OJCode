#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n, res = 0, mx = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x)
		{
			mx = max(mx, x), res++;
		}
	}
	cout << res + mx << endl;
	return 0;
}