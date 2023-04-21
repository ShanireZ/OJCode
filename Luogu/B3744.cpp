#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	long long n, x, y;
	cin >> n >> x >> y;
	cout << 1 + (n - 1) * x / (x * y / __gcd(x, y));
	return 0;
}