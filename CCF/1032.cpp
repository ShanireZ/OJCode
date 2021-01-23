#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, i, j, k;
	cin >> n;
	for(i = 1; i <= n*2-1; i++)
	{
		for(j = 1; j <= abs(n-i); j++)
		{
			cout << " ";
		}
		
		if(i <= n)
		{
			k = i;
		}else
		{
			k = abs(i-n*2);
		}
		
		for(j = 1; j <= k*2-1; j++)
		{
			cout << j;
		}
		cout << endl;
	}
	return 0;
}
