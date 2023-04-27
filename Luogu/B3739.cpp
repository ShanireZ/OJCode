#include <iostream>
using namespace std;
int nums[1005], top;
int main()
{
	int a, n;
	cin >> a >> n;
	nums[0] = 1;
	while (n--)
	{
		for (int i = 0; i <= top; i++)
		{
			nums[i] *= a;
		}
		for (int i = 0; i <= top; i++)
		{
			nums[i + 1] += nums[i] / 10, nums[i] %= 10;
		}
		top += (nums[top + 1] != 0);
	}
	int j = 0, o = 0;
	for (int i = 0; i <= top; i++)
	{
		nums[i] % 2 == 0 ? o++ : j++;
	}
	cout << j - o << "\n";
	return 0;
}