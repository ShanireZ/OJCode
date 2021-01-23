#include <iostream>
#include <algorithm>
using namespace std;
int nums[105];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums, nums + n);
	int m = unique(nums, nums + n) - nums;
	cout << m << endl;
	for (int i = 0; i < m; i++)
	{
		cout << nums[i] << " ";
	}
	return 0;
}