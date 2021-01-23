#include <iostream>
#include <algorithm>
using namespace std;
long long candy[100005];
int main()
{
	int n, x;
	long long tot = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		long long num;
		cin >> num;
		candy[i] += num;
		if (candy[i] > x)
		{
			tot += candy[i] - x;
			num -= candy[i] - x;
		}
		candy[i + 1] += num;
	}
	cout << tot;
	return 0;
}