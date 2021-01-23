#include <iostream>
using namespace std;
int nei[105];
int main()
{
	int m, n;
	cin >> m >> n;
	int tot = 0, pos = 1;
	for(int i = 1; i <= m; i++)
	{
		nei[i] = -1;	
	}
	for(int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		int in = 0;
		for(int j = 1; j <= m; j++)
		{
			if(nei[j] == num)
			{
				in = 1;
				break;	
			}
		}
		if(in == 0)
		{
			tot++;
			nei[pos] = num;
			pos++;
			if(pos > m)
			{
				pos = 1;
			}
		}
	}
	cout << tot;
	return 0;
}