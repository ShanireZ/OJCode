#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
long long v[35], tot, ans, n;
set<int> s[20];
void dfs1(int id, int cnt, int now) // 前半段
{
    s[cnt].insert(now); // 新情况统计
    if (id > n / 2)
    {
        return;
    }
    dfs1(id + 1, cnt + 1, now + v[id]); // 选
    dfs1(id + 1, cnt, now);             // 不选
}
void dfs2(int id, int cnt, int now) // 后半段
{
    auto itr = s[n / 2 - cnt].lower_bound(tot / 2 - now);
    if (itr != s[n / 2 - cnt].end())
    {
        ans = min(ans, abs(tot - 2 * (now + *itr)));
    }
    auto itl = itr;
    if (itl != s[n / 2 - cnt].begin())
    {
        itl--;
        ans = min(ans, abs(tot - 2 * (now + *itl)));
    }
    if (id > n)
    {
        return;
    }
    dfs2(id + 1, cnt + 1, now + v[id]); // 选
    dfs2(id + 1, cnt, now);             // 不选
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        tot = 0, ans = 1e15;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            tot += v[i];
        }
        if (n % 2 == 1) // 补齐偶数个数
        {
            v[++n] = 0;
        }
        for (int i = 1; i <= n / 2; i++)
        {
            s[i].clear();
        }
        dfs1(1, 0, 0);
        dfs2(n / 2 + 1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}