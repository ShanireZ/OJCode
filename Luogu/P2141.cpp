#include <iostream>
using namespace std;
int check[20005];
int nums[105];
int main()
{
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int x = nums[i] + nums[j];
            check[x] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if(check[nums[i]] == 1)
        {
            tot++;   
        }
	}
	cout << tot;
	return 0;
}