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
	for (int i = 0; i <= n - 1; i++)
	{
		int t = i % 2;
		if (t == 0) //最大
		{
			cout << a[n - i / 2] << endl;
		}
		else //最小
		{
			cout << a[1 + i / 2] << endl;
		}
	}
	return 0;
}