#include <cstdio>
using namespace std;

int main()
{
	double a, b;
	long c;
	scanf("%lf %lf", &a, &b);
	c = a / b;
	a = a - c * b;	
	printf("%.2lf", a);
	
	return 0;
}
