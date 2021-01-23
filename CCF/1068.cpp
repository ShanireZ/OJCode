#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int a[100][100], b[100][100];
int m, n;
string s;
int ChangePos(char c, int x, int y, bool trig)
{
	int temp;
	if (c == 'A')
	{
		temp = x;
		x = y;
		y = m - temp - 1;
	}
	else if (c == 'B')
	{
		temp = x;
		x = n - y - 1;
		y = temp;
	}
	else if (c == 'C')
	{
		y = n - y - 1;
	}
	else
	{
		x = m - x - 1;
	}
	if (!trig)
	{
		return x;
	}
	else
	{
		return y;
	}
}
void Step()
{
	for (int k = 0; k < s.length(); k++)
	{
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				b[ChangePos(s[k], i, j, 0)][ChangePos(s[k], i, j, 1)] = a[i][j];
			}
		}
		if (s[k] == 'A' || s[k] == 'B')
		{
			swap(m, n);
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> s;
	Step();
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}