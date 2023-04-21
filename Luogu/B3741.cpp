#include <iostream>
using namespace std;
int main()
{
	int a1, p1, a2, p2;
	scanf("%d %d\n%d %d", &a1, &p1, &a2, &p2);
	if (a1 > a2 || (a1 == a2 && p1 < p2))
	{
		printf("\"\\n\"");
	}
	else
	{
		printf("\"\\t\"");
	}
	return 0;
}