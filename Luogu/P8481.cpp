#include <algorithm>
#include <iostream>
using namespace std;
int nums[1200005], n, q, x, ans;
void dfs(int l, int r, int step)
{
	if (l == r)
	{
		ans = min(ans, step);
		return;
	}
	int mid = (l + r) / 2;
	(nums[mid] < x) ? dfs(mid + 1, r, step + 1) : dfs(l, mid, step + 1);
	mid = (l + r + 1) / 2;
	(nums[mid] <= x) ? dfs(mid, r, step + 1) : dfs(l, mid - 1, step + 1);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	cin >> q;
	while (q--)
	{
		cin >> x;
		ans = 50, dfs(1, n, 0);
		cout << ans << endl;
	}
	return 0;
}