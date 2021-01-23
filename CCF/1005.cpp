#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	double r, x, p; 
	scanf("%lf %lf %lf", &r, &x, &p);
	x = x * pow((1 + r / 100), p); 
	printf("%.2lf", x);
	
	return 0;
}
