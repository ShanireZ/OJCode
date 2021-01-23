#include <iostream>
using namespace std;
bool tree[10005];
int main()
{
	int l, m;
	cin >> l >> m;
	for (int i = 1; i <= m; i++)
	{
		int st, end;
		cin >> st >> end;
		for (int j = st; j <= end; j++)
		{
			tree[j] = 1;
		}
	}
	int tot = 0;
	for (int i = 0; i <= l; i++)
	{
		if (tree[i] == 0)
		{
			tot++;
		}
	}
	cout << tot;
	return 0;
}