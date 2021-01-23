#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int lc, rc, w;
};
Node ns[105];
int sub[105], d[105], vis[105];
int mind, root;
void dfs(int x) //更新子树权值和
{
    if (ns[x].lc != 0)
    {
        dfs(ns[x].lc);
    }
    if (ns[x].rc != 0)
    {
        dfs(ns[x].rc);
    }
    sub[x] = sub[ns[x].lc] + sub[ns[x].rc] + ns[x].w; //树的权值和=左子树+右子树+自己
    if (x != root)                                    //统计根节点的距离和
    {
        d[root] += sub[x];
    }
}
//子节点为c 父节点为x
// d[c] = d[x] - sub[c] + (sub[root] - sub[c])
// 对于d[x]而言，以子节点c为子树的部分，所有节点减小了距离1，所以-sub[c] * 1
// 其他部分为 sub[root] - sub[c],每个节点增加了距离1，所以+(sub[root] - sub[c])
void count(int x)
{
    if (ns[x].lc != 0)
    {
        int c = ns[x].lc;
        d[c] = d[x] - sub[c] + (sub[root] - sub[c]);
        mind = min(mind, d[c]);
        count(c);
    }
    if (ns[x].rc != 0)
    {
        int c = ns[x].rc;
        d[c] = d[x] - sub[c] + (sub[root] - sub[c]);
        mind = min(mind, d[c]);
        count(c);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].w >> ns[i].lc >> ns[i].rc;
        vis[ns[i].lc] = vis[ns[i].rc] = 1; //标记所有子节点 为了找到根节点
    }
    for (int i = 1; i <= n; i++) //找到根节点
    {
        if (vis[i] == 0)
        {
            root = i;
            break;
        }
    }
    dfs(root); //从根节点遍历 更新子树的权值和
    mind = d[root];
    count(root); //从根节点开始更新每个节点的距离和
    cout << mind;
    return 0;
}