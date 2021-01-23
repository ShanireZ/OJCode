#include <iostream>
#include <algorithm>
using namespace std;
long long d[1000005];
int main()
{
	int n, k;
	long long maxd = 0;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++)
	{
		long long num;
		cin >> num;
		d[i] = d[i - 1] + num;
	}
	for (int i = 1; i <= n - k; i++)
	{
		long long dis = d[i + k - 1] - d[i - 1];
		maxd = max(maxd, dis);
	}
	cout << d[n - 1] - maxd;
	return 0;
}