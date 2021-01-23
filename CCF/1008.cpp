#include <cstdio>
#include <cmath> 
using namespace std;

int main()
{
	int a, b, i, j, k;
	scanf("%d", &a);
	i = a / 100;
	j = (a % 100) / 10;
	k = a % 10;
	b = pow(i, 3) + pow(j, 3) + pow(k, 3);
	if(a == b)
	{
		printf("YES");
	}else
	{
		printf("NO");
	}
	
	return 0;
}
