#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ans = 5000;
	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		ans = min(ans, num);
	}
	cout << ans;
	return 0;
}