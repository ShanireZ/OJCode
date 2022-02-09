#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    vector<int> to;
    int totw, totdis, fa;
    //! totw以该节点为根的子树w和 totdis整棵树以该节点为根时的距离和
};
Node ns[50005];
int root, n, pos;
void init(int now) //! 预处理每个点的totw 并求出root的totdis作为基准
{
    ns[now].totw = 1;
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int to = ns[now].to[i];
        if (to == ns[now].fa)
        {
            continue;
        }
        ns[to].fa = now;
        init(to);
        ns[now].totw += ns[to].totw;
    }
    if (now != root)
    {
        ns[root].totdis += ns[now].totw;
    }
}
void trans(int now) //! 计算每个点的totdis
{
    if (now != root)
    {
        ns[now].totdis = ns[ns[now].fa].totdis + (n - ns[now].totw) - ns[now].totw;
        if (ns[pos].totdis > ns[now].totdis || (ns[pos].totdis == ns[now].totdis && pos > now))
        {
            pos = now;
        }
    }
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int to = ns[now].to[i];
        if (to == ns[now].fa)
        {
            continue;
        }
        trans(to);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        ns[u].to.push_back(v), ns[v].to.push_back(u);
    }
    root = 1;
    init(root);
    pos = root;
    trans(root);
    cout << pos << " " << ns[pos].totdis << endl;
    return 0;
}