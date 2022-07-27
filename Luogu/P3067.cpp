#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n, ans, pos, a[25], final[1200005];
map<int, int> mp;
vector<int> as[60005];
void dfs1(int now, int tot, int state) // 当前数字下标 组1的a-b 前半段选择状态
{
    if (now == n / 2)
    {
        if (mp[tot] == 0)
        {
            mp[tot] = ++pos;
        }
        as[mp[tot]].push_back(state);
        return;
    }
    int ns = state | (1 << now);
    dfs1(now + 1, tot + a[now], ns); // 放在组1
    dfs1(now + 1, tot - a[now], ns); // 放在组2
    dfs1(now + 1, tot, state);
}
void dfs2(int now, int tot, int state)
{
    if (now == n)
    {
        int id = mp[tot];
        for (int i = 0; i < as[id].size(); i++)
        {
            final[state | as[id][i]] = 1;
        }
        return;
    }
    int ns = state | (1 << now);
    dfs2(now + 1, tot + a[now], ns);
    dfs2(now + 1, tot - a[now], ns);
    dfs2(now + 1, tot, state);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs1(0, 0, 0);
    dfs2(n / 2, 0, 0);
    for (int i = 1; i <= 1050000; i++)
    {
        ans += final[i];
    }
    cout << ans << '\n';
    return 0;
}