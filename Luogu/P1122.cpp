#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    vector<int> to;
    int fa, v, w;
};
Node ns[16005];
int n, root, ans;
void dfs(int now)
{
    ns[now].w = ns[now].v;
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int t = ns[now].to[i];
        if (t == ns[now].fa)
        {
            continue;
        }
        ns[t].fa = now;
        dfs(t);
        ns[now].w = max(ns[now].w, ns[now].w + ns[t].w);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].v;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].to.push_back(b);
        ns[b].to.push_back(a);
    }
    root = 1;
    dfs(root);
    ans = ns[root].w;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, ns[i].w);
    }
    cout << ans << endl;
    return 0;
}