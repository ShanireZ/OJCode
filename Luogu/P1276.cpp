#include <iostream>
using namespace std;
int t[10005]; //0樹 1空 2樹苗
int main()
{
	int l, n, tot1 = 0, tot2 = 0;
	cin >> l >> n;
	for (int i = 1; i <= n; i++)
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1) //種樹苗
		{
			for (int j = x; j <= y; j++)
			{
				if (t[j] == 1)
				{
					t[j] = 2;
				}
			}
		}
		else //砍樹
		{
			for (int j = x; j <= y; j++)
			{
				if (t[j] == 2)
				{
					tot2++;
				}
				t[j] = 1;
			}
		}
	}
	int tot = 0;
	for (int i = 0; i <= l; i++)
	{
		if (t[i] == 2)
		{
			tot1++;
		}
	}
	cout << tot1 << endl
		 << tot2;
	return 0;
}