#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Node
{
    int pre, down, id;
};
vector<Node> ns[MX];
vector<int> to[MX], root;
int ans[MX], anc[MX][20], p2[20], cnt[MX], n, m;
int findAnc(int x, int p)
{
    for (int i = 16; i >= 0 && p; i--)
    {
        if (p2[i] <= p)
        {
            x = anc[x][i], p -= p2[i];
        }
    }
    return x;
}
void dfs(int now, int dp)
{
    cnt[dp]++;
    for (int i = 0; i < (int)ns[now].size(); i++)
    {
        ns[now][i].pre = cnt[dp + ns[now][i].down];
    }
    for (int nxt : to[now])
    {
        dfs(nxt, dp + 1);
    }
    for (int i = 0; i < (int)ns[now].size(); i++)
    {
        ans[ns[now][i].id] = cnt[dp + ns[now][i].down] - ns[now][i].pre;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int fa;
        cin >> fa;
        if (fa == 0)
        {
            root.push_back(i);
        }
        else
        {
            to[fa].push_back(i), anc[i][0] = fa;
        }
    }
    p2[0] = 1;
    for (int j = 1; j <= 16; j++)
    {
        p2[j] = p2[j - 1] * 2;
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int v, p;
        cin >> v >> p;
        int pos = findAnc(v, p);
        ns[pos].push_back(Node{0, p, i});
    }
    for (int r : root)
    {
        dfs(r, 1);
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i])
        {
            ans[i]--;
        }
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
// TAG: 倍增 LCA 树上前缀统计