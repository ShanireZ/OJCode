#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Line
{
    int to, d, c;
};
struct Node
{
    int in, d;
    vector<Line> ls;
};
Node ns[505];
queue<int> pt;
int n, m, x;
vector<int> allc;
int SPFA(int lmt)
{
    int minc = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        ns[i].d = 0x3f3f3f3f;
    }
    ns[1].d = 0;
    ns[1].in = 1;
    pt.push(1);
    while (pt.size())
    {
        int from = pt.front();
        ns[from].in = 0;
        pt.pop();
        for (int i = 0; i < ns[from].ls.size(); i++)
        {
            int cto = ns[from].ls[i].c;
            if (cto < lmt)
            {
                continue;
            }
            minc = min(minc, cto);
            int to = ns[from].ls[i].to;
            int dto = ns[from].ls[i].d;
            if (dto + ns[from].d < ns[to].d)
            {
                ns[to].d = dto + ns[from].d;
                if (ns[to].in == 0)
                {
                    ns[to].in = 1;
                    pt.push(to);
                }
            }
        }
    }
    return minc;
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
    {
        int a, b, l, c;
        cin >> a >> b >> l >> c;
        Line tmp1, tmp2;
        tmp1.d = tmp2.d = l;
        tmp1.c = tmp2.c = c;
        tmp1.to = b, tmp2.to = a;
        ns[a].ls.push_back(tmp1);
        ns[b].ls.push_back(tmp2);
        allc.push_back(c);
    }
    sort(allc.begin(), allc.end());
    allc.erase(unique(allc.begin(), allc.end()), allc.end());
    int ans = 0x3f3f3f3f;
    //枚举所有容量作为最小容量限制 每次SPFA时不走长度低于lmt的边
    for (int i = 0; i < allc.size(); i++)
    {
        int minc = SPFA(allc[i]);
        if (ns[n].d != 0x3f3f3f3f)
        {
            ans = min(ans, ns[n].d + x / minc);
        }
    }
    cout << ans;
    return 0;
}