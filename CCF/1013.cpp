#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a + b <= c || a + c <= b || b + c <= a)
	{
		printf("NO");
	}
	else if (a == b && b == c)
	{
		printf("Equilateral");
	}
	else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2))
	{
		printf("Right");
	}
	else
	{
		printf("General");
	}

	return 0;
}
