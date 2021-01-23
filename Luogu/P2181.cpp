#include <iostream>
using namespace std;
int main()
{
	unsigned long long n, ans;
	cin >> n;
	ans = n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) / 4;
	cout << ans;
	return 0;
}