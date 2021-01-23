#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char a[101];
	int i = 0, j;
	while((a[i] = getchar()) != '\n')
	{
		i++;
	}
	
	for(j = 0; j < i; j++)
	{
		if(a[j] >= 'a' && a[j] <= 'z')
		{
			a[j] += 3;
			if(a[j] > 'z')
			{
				a[j] -= 26;
			}
		}else if(a[j] >= 'A' && a[j] <= 'Z')
		{
			a[j] += 3;
			if(a[j] > 'Z')
			{
				a[j] -= 26;
			}
		}
		cout << a[j];
	}
	return 0;
}
