#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
set<int> s;
unordered_map<int, int> lc, rc, dp;
void dfs(int now)
{
    if (lc[now])
    {
        dfs(lc[now]);
    }
    if (rc[now])
    {
        dfs(rc[now]);
    }
    cout << now << "\n";
}
int main()
{
    int n, h, v, root;
    cin >> n >> v;
    root = v, dp[v] = h = 1, s.insert(v);
    for (int i = 2; i <= n; i++)
    {
        cin >> v;
        auto p = s.lower_bound(v);
        if (p != s.end() && lc[*p] == 0)
        {
            lc[*p] = v;
        }
        else
        {
            p--;
            rc[*p] = v;
        }
        dp[v] = dp[*p] + 1;
        s.insert(v), h = max(h, dp[v]);
    }
    cout << "deep=" << h << endl;
    dfs(root);
    return 0;
}