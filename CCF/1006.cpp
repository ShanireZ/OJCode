#include <cstdio>
using namespace std;
#define all 20

int main()
{
	int a, b, c; 
	scanf("%d %d %d", &a, &b, &c);
	a = all - a - b - c; 
	printf("%d", a);
	
	return 0;
}
