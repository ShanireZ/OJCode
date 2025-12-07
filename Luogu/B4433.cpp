#include <algorithm>
#include <iostream>
using namespace std;
int v[1005], c[1005], n, T, x;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> c[i];
		c[i] += c[i - 1];
	}
	cin >> T;
	while (T--)
	{
		cin >> x;
		int pos = lower_bound(c + 1, c + n + 1, x) - c;
		cout << v[pos] << endl;
	}
	return 0;
}