#include <algorithm>
#include <iostream>
using namespace std;
long long nums[15];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans = ans * nums[i] / __gcd(ans, nums[i]);
	}
	cout << ans << endl;
	return 0;
}