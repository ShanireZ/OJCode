#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int x, up, down, opt;
};
Edge es[2005];
int n, epos, spos, ls[2005], v[2005];
long long ans;
bool cmp(Edge a, Edge b)
{
    return a.x < b.x;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        es[++epos] = Edge{a, b, d, 1};
        es[++epos] = Edge{c, b, d, -1};
        ls[++spos] = b, ls[++spos] = d;
    }
    sort(es + 1, es + 1 + epos, cmp);
    sort(ls + 1, ls + 1 + spos);
    spos = unique(ls + 1, ls + 1 + spos) - ls - 1;
    for (int i = 1, pre = -1e8, y = 0; i <= epos; i++)
    {
        int up = lower_bound(ls + 1, ls + 1 + spos, es[i].up) - ls;
        int down = lower_bound(ls + 1, ls + 1 + spos, es[i].down) - ls;
        ans += 1ll * (es[i].x - pre) * y;
        for (int j = down; j < up; j++)
        {
            v[j] += es[i].opt;
            if (es[i].opt == 1 && v[j] == 1)
            {
                y += ls[j + 1] - ls[j];
            }
            if (es[i].opt == -1 && v[j] == 0)
            {
                y -= ls[j + 1] - ls[j];
            }
        }
        pre = es[i].x;
    }
    cout << ans << endl;
    return 0;
}