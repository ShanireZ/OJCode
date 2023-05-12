#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long a, b;
		cin >> a >> b;
		cout << max(b - a * 3, 0ll) << " " << (b - a * 2) / 2 << "\n";
	}
	return 0;
}