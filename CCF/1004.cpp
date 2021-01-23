#include <cstdio>
using namespace std;

int main()
{
	long a, m, n;
	scanf("%ld %ld %ld", &n, &m, &a);
	n = n / a;
	m = m / a;
	printf("%ld", n*m);
	
	return 0;
}
