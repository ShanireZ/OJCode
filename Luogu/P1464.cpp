#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
long long w[21][21][21];
long long fun(long long a, long long b, long long c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		return fun(20, 20, 20);
	}
	else if (w[a][b][c] == 0)
	{
		if (a < b && b < c)
		{
			w[a][b][c] = fun(a, b, c - 1) + fun(a, b - 1, c - 1) - fun(a, b - 1, c);
		}
		else
		{
			w[a][b][c] = fun(a - 1, b, c) + fun(a - 1, b - 1, c) + fun(a - 1, b, c - 1) - fun(a - 1, b - 1, c - 1);
		}
	}
	return w[a][b][c];
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	while (a != -1 || b != -1 || c != -1)
	{
		cout << "w(" << a << ", " << b << ", " << c << ") = " << fun(a, b, c) << endl;
		cin >> a >> b >> c;
	}
	return 0;
}