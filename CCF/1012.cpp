#include <cstdio>
using namespace std;

int main()
{
	int a;
	char b;
	scanf("%d", &a);
	if(a % 123 >= 97 && a % 123 <= 122)
	{
		b = a % 123;
	}else if(a % 91 >= 65 && a % 91 <= 90)
	{
		b = a % 91;
	}else
	{
		b = '*'; 
	}
	printf("%c", b);
	
	return 0;
}
