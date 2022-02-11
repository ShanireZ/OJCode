#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    vector<int> to;
    int fa;
};
Node ns[1505];
int n, root, ans[1505][2];
void dfs(int now)
{
    ans[now][1] = 1, ans[now][0] = 0;
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int t = ns[now].to[i];
        if (t == ns[now].fa)
        {
            continue;
        }
        ns[t].fa = now;
        dfs(t);
        ans[now][0] += ans[t][1];
        ans[now][1] += min(ans[t][0], ans[t][1]);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int now, k;
        cin >> now >> k;
        for (int j = 1; j <= k; j++)
        {
            int t;
            cin >> t;
            ns[now].to.push_back(t);
            ns[t].to.push_back(now);
        }
    }
    root = 0;
    dfs(root);
    cout << min(ans[root][0], ans[root][1]) << endl;
    return 0;
}