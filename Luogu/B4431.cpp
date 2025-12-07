#include <algorithm>
#include <iostream>
using namespace std;
int n, a, b, ans;
int main()
{
	cin >> n >> a;
	for (int i = 2; i <= n; i++)
	{
		cin >> b;
		ans += (a % 2 != b % 2);
		a = b;
	}
	cout << ans << endl;
	return 0;
}