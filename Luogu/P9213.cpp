#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n, x, y;
		scanf("%lld %lld %lld", &n, &x, &y);
		printf("%lld\n", 1 + (n - 1) / (y / __gcd(x, y)));
	}
	return 0;
}