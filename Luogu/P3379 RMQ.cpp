#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
int n, m, root, dpos, epos;
int fa[MX], dfn[MX], fst[MX], back[MX], st[MX * 2][20];
// fa父节点编号 dfn节点dfn序号 back每个dfn序号属于哪个节点
// fst每个节点第一次出现在欧拉序中的位置 st表负责维护欧拉序的最小值
vector<int> to[MX];
void init(int now)
{
    if (dfn[now] == 0)
    {
        dfn[now] = ++dpos;
        back[dpos] = now;
    }
    st[++epos][0] = dfn[now];
    if (fst[now] == 0)
    {
        fst[now] = epos;
    }
    for (int i = 0; i < int(to[now].size()); i++)
    {
        int nxt = to[now][i];
        if (nxt != fa[now])
        {
            fa[nxt] = now;
            init(nxt);
            st[++epos][0] = dfn[now];
        }
    }
}
int main()
{
    cin >> n >> m >> root;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b), to[b].push_back(a);
    }
    init(root);
    for (int i = 1; i <= log2(epos); i++)
    {
        int len = pow(2, i);
        for (int j = 1; j + len - 1 <= epos; j++)
        {
            st[j][i] = min(st[j][i - 1], st[j + len / 2][i - 1]);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (fst[a] > fst[b])
        {
            swap(a, b);
        }
        int ex = log2(fst[b] - fst[a] + 1);
        int len = pow(2, ex);
        cout << back[min(st[fst[a]][ex], st[fst[b] - len + 1][ex])] << endl;
    }
    return 0;
}