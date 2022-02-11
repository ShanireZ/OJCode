#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    vector<int> to;
    int fa, ok, cnt;
};
Node ns[100005];
int n, root, ans;
void dfs(int now)
{
    ns[now].cnt = 1;
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int t = ns[now].to[i];
        if (t == ns[now].fa)
        {
            continue;
        }
        ns[t].fa = now;
        dfs(t);
        ns[now].ok += ns[t].ok;
        if (ns[t].to.size() == 1)
        {
            ns[now].cnt++;
        }
    }
    ns[now].ok += ns[now].cnt / 2;
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].to.push_back(b);
        ns[b].to.push_back(a);
    }
    root = 1;
    dfs(root);
    cout << ns[root].ok << endl;
    return 0;
}