#include <iostream>
#include <vector>
using namespace std;
int n, root, r[6005], fa[6005], tot[6005][2];
vector<int> to[6005];
void dfs(int now)
{
	tot[now][1] = r[now];
	for (int i = 0; i < int(to[now].size()); i++)
	{
		int nxt = to[now][i];
		dfs(nxt);
		tot[now][1] += tot[nxt][0];
		tot[now][0] += max(tot[nxt][0], tot[nxt][1]);
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> r[i];
	}
	for (int i = 1; i < n; i++)
	{
		int l, k;
		cin >> l >> k;
		to[k].push_back(l), fa[l] = k;
	}
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == 0)
		{
			root = i;
			break;
		}
	}
	dfs(root);
	cout << max(tot[root][0], tot[root][1]) << endl;
	return 0;
}