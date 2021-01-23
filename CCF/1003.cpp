#include <cstdio>
using namespace std;

int main()
{
	int a;
	scanf("%d", &a);
	int i, j, k;
	i = a / 100;
	j = (a % 100) / 10;
	k = a % 10;
	a = i * 100000 + j * 10000 + k * 1000 + a;
	a = a / 7 / 11 / 13; 
	printf("%d", a);
	return 0;
}
