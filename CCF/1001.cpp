#include <cstdio>
using namespace std;

int main()
{
	float c, f;
	scanf("%f", &f);
	c = (f - 32) * 5 / 9;
	printf("%.4f", c);
	
	return 0;
}
