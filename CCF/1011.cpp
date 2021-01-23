#include <cstdio>
using namespace std;

int main()
{
	double a, b;
	scanf("%lf %lf", &a, &b);
	if(a > 1.0 || a < -1.0 || b > 1.0 || b < -1.0)
	{
		printf("No");
	}else
	{
		printf("Yes");
	}
	
	return 0;
}
