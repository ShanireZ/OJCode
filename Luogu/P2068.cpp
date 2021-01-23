#include <iostream>
using namespace std;
long long tree[100005];
int n, w;
int lowbit(int x)
{
	return x & -x;
}
void edit(int id, int add)
{
	while (id <= n)
	{
		tree[id] += add;
		id += lowbit(id);
	}
}
long long query(int id)
{
	long long ans = 0;
	while (id)
	{
		ans += tree[id];
		id -= lowbit(id);
	}
	return ans;
}
int main()
{
	cin >> n >> w;
	for (int i = 1; i <= w; i++)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'x')
		{
			edit(a, b);
		}
		else
		{
			cout << query(b) - query(a - 1) << endl;
		}
	}
	return 0;
}