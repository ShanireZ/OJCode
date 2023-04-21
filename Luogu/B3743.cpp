#include <iostream>
using namespace std;
int s[10] = {1, 0, 1, 0, 0, 0, 1, 0, 2, 1}, ans;
int main()
{
	long long x;
	scanf("%lld", &x);
	while (x)
	{
		ans += s[x % 10];
		x /= 10;
	}
	printf("%d\n", ans);
	return 0;
}