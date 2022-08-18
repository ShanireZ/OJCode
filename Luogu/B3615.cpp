#include <iostream>
using namespace std;
int a[520][520], b[520][520], c[520][520];
int seeda, seedb, n = 512;
int main()
{
	cin >> seeda >> seedb;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = ((i | j) + j) ^ seeda;
			b[i][j] = ((i & j) + i) ^ seedb;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			ans ^= c[i][j];
		}
		cout << ans << endl;
	}
	return 0;
}