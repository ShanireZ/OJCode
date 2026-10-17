#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
int n, m, root, dpos, epos;
int fa[MX], dfn[MX], fst[MX], back[MX], st[MX * 2][20];
// fa父節點編號 dfn節點dfn序號 back每個dfn序號屬於哪個節點
// fst每個節點第一次出現在歐拉序中的位置 st表負責維護歐拉序的最小值
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