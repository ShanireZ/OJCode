#include<cstdio>

int main()
{
	int n, a, b, count = 1, countMax = 0;
	scanf("%d %d", &n, &a);
	
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d", &b);
		if(a < b)
		{
			count++;
			if(countMax < count)
			{
				countMax = count;
			}
		}else
		{
			count = 1;
		}
		a = b;
	}

	printf("%d", countMax);
	return 0;
}
