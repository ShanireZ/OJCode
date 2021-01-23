#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, tot = 0, pre = 0, cur;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cur;
		tot += max(cur - pre, 0);
		pre = cur;
	}
	cout << tot;
	return 0;
}