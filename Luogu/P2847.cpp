#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int a, b, dis;
    bool operator<(const Edge oth) const
    {
        return dis < oth.dis;
    }
};
Edge es[1000005];
int pos[1005][2], g[1005], cnt;
int dfn(int x)
{
    return (g[x] != x) ? g[x] = dfn(g[x]) : x;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i;
        cin >> pos[i][0] >> pos[i][1];
        for (int j = i - 1; j >= 1; j--)
        {
            es[++cnt] = Edge{i, j, (pos[i][0] - pos[j][0]) * (pos[i][0] - pos[j][0]) + (pos[i][1] - pos[j][1]) * (pos[i][1] - pos[j][1])};
        }
    }
    sort(es + 1, es + 1 + cnt);
    int tot = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int ga = dfn(es[i].a), gb = dfn(es[i].b);
        if (ga != gb)
        {
            g[ga] = gb, tot++;
        }
        if (tot == n - 1)
        {
            cout << es[i].dis << endl;
            break;
        }
    }
    return 0;
}