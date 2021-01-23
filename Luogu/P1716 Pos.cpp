#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int da = n, xiao = 1;
	for (int i = 1; i <= n; i++)
	{
		int t = i % 2;
		if (t == 1) //最大
		{
			cout << a[da--] << endl;
		}
		else //最小
		{
			cout << a[xiao++] << endl;
		}
	}
	return 0;
}