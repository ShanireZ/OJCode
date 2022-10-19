#include <iostream>
using namespace std;
int main()
{
	long long x, y, n;
	cin >> x >> y >> n;
	long long ans = min((x - 1) * n, n / 10 * (y - 1) + n % 10 * (x - 1));
	cout << ans << endl;
	return 0;
}