#include <iostream>
using namespace std;
long long m, n;

long long Gcd(long long a, long long b)
{
	long long r = a % b;
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

long long Make()
{
	return m * n / Gcd(m, n);
}

int main()
{
	cin >> m >> n;
	cout << Make();
	return 0;
}
