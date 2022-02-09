#include <iostream>
using namespace std;
struct Node
{
    int fa, lc, rc, w, totw, totdis;
    //! totw以该节点为根的子树w和 totdis整棵树以该节点为根时的距离和
};
Node ns[105];
int root, n, all, ans;
void init(int now) //! 预处理每个点的totw 并求出root的totdis作为基准
{
    if (ns[now].lc)
    {
        init(ns[now].lc);
    }
    if (ns[now].rc)
    {
        init(ns[now].rc);
    }
    ns[now].totw = ns[now].w + ns[ns[now].lc].totw + ns[ns[now].rc].totw;
    if (now != root)
    {
        ns[root].totdis += ns[now].totw;
    }
}
void trans(int now) //! 计算每个点的totdis
{
    if (now != root)
    {
        //! 相较于以now父节点为整棵树根节点时
        //! 以now为根节点的子树上每个点距离都-1 其他每个点的距离都+1
        ns[now].totdis = ns[ns[now].fa].totdis + (all - ns[now].totw) - ns[now].totw;
        ans = min(ans, ns[now].totdis);
    }
    if (ns[now].lc)
    {
        trans(ns[now].lc);
    }
    if (ns[now].rc)
    {
        trans(ns[now].rc);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].w >> ns[i].lc >> ns[i].rc;
        ns[ns[i].lc].fa = ns[ns[i].rc].fa = i;
        all += ns[i].w;
    }
    for (int i = 1; i <= n; i++) //! 寻找初始状态的根节点
    {
        if (ns[i].fa == 0)
        {
            root = i;
            break;
        }
    }
    init(root);
    ans = ns[root].totdis;
    trans(root);
    cout << ans << endl;
    return 0;
}