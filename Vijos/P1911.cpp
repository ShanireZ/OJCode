#include <iostream>
#include <algorithm>
using namespace std;
int nums[105];
int check[105];
int main()
{
	int n, tot = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	sort(nums + 1, nums + 1 + n);
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				if (check[k] == 1)
				{
					continue;
				}
				if (nums[i] + nums[j] == nums[k])
				{
					tot++;
					check[k] = 1;
					break;
				}
			}
		}
	}
	cout << tot;
	return 0;
}