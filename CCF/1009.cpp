#include <cstdio>
using namespace std;

int main()
{
	int m, w, total;
	scanf("%d %d", &m, &w);
	total = m + w;
	if(total < 10)
	{
		printf("water");
	}else if(total >= 10 && m > w)
	{
		printf("tree");
	}else
	{
		printf("tea");
	}
		
	return 0;
}
