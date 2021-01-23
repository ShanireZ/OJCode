#include <cstdio>
#include <cmath>
using namespace std;
double x;

double f(int n)
{
	double output;
	if (n == 1)
	{
		output = sqrt(n + x);
	}
	else
	{
		output = sqrt(n + f(n - 1));
	}
	return output;
}

int main()
{
	int n;
	scanf("%lf %d", &x, &n);
	printf("%.2lf", f(n));
	return 0;
}