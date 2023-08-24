#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 400005
int n, npos, root;
long long ans;
vector<int> s[MX];
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
void dfs(int &now)
{
    now = ++npos;
    int val = read(), lc = 0, rc = 0;
    if (val == 0)
    {
        dfs(lc), dfs(rc);
        if (s[lc].size() > s[rc].size())
        {
            swap(lc, rc);
        }
        long long add = 0, lsz = s[lc].size(), rsz = s[rc].size();
        for (int num : s[lc])
        {
            add += upper_bound(s[rc].begin(), s[rc].end(), num) - s[rc].begin();
        }
        ans += min(add, lsz * rsz - add);
        for (int num : s[lc])
        {
            s[rc].insert(upper_bound(s[rc].begin(), s[rc].end(), num), num);
        }
        now = rc, vector<int>().swap(s[lc]);
    }
    else
    {
        s[now].push_back(val);
    }
}
int main()
{
    n = read();
    dfs(root);
    printf("%lld\n", ans);
    return 0;
}
// TAG: 线段树合并 启发式合并 DSU on tree