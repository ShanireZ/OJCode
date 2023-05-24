#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, m;
		cin >> n >> m;
		cout << (n - 1) * ((m - 1) * 2 + 1) + (m - 1) << "\n";
	}
	return 0;
}