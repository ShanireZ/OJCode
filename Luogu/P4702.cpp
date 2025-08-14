#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	long long n, tot = 0;
	cin >> n;
	while (n--)
	{
		long long x;
		cin >> x;
		tot += x;
	}
	cout << (tot % 2 ? "Alice" : "Bob") << endl;
	return 0;
}