#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nums[100005], tree[100005], sz;
vector<int> all;
int lowbit(int x)
{
    return x & -x;
}
void edit(int id, int add)
{
    while (id <= sz)
    {
        tree[id] += add;
        id += lowbit(id);
    }
}
int query(int id)
{
    int ans = 0;
    while (id)
    {
        ans += tree[id];
        id -= lowbit(id);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        all.push_back(nums[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    sz = all.size();
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(all.begin(), all.end(), nums[i]) - all.begin() + 1;
        maxn = max(maxn, query(sz) - query(id));
        edit(id, 1);
    }
    cout << maxn + 1;
    return 0;
}