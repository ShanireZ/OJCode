#include <cstdio>
using namespace std;

int main()
{
	int a;
	float b;
	scanf("%d", &a);
	if(a <= 10)
	{
		b = a * 0.8 + 0.2;
		printf("%.2f", b);
	}else if(a > 10 && a <= 20)
	{
		b = (a - 10) * 0.75 + 0.2 + 8;
		printf("%.2f", b);
	}else if(a > 20 && a <= 30)
	{
		b = (a - 20) * 0.70 + 0.2 + 8 + 7.5;
		printf("%.2f", b);
	}else
	{
		printf("Fail");
	}
		
	return 0;
}
