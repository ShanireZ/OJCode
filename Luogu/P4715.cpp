#include <iostream>
#include <cmath>
using namespace std;
int a[500][2]; //0:id  1:level
int main()
{
	int n, p = 1;
	cin >> n;
	for (int i = pow(2, n); i <= pow(2, n + 1) - 1; i++) //满二叉树最底层
	{
		cin >> a[i][1];
		a[i][0] = p++;
	}
	for (int i = pow(2, n) - 1; i >= 1; i--) //完善二叉树
	{
		if (a[i * 2][1] > a[i * 2 + 1][1])
		{
			a[i][1] = a[i * 2][1];
			a[i][0] = a[i * 2][0];
		}
		else
		{
			a[i][1] = a[i * 2 + 1][1];
			a[i][0] = a[i * 2 + 1][0];
		}
	}
	if (a[1][0] == a[2][0])
	{
		cout << a[3][0];
	}
	else
	{
		cout << a[2][0];
	}

	return 0;
}