#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Line
{
    int to, dis;
};
struct Node
{
    int d, in;
    vector<Line> ls;
};
Node ns[2505];
queue<int> pt;
int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Line tmp1, tmp2;
        tmp1.dis = tmp2.dis = w;
        tmp1.to = v, tmp2.to = u;
        ns[u].ls.push_back(tmp1);
        ns[v].ls.push_back(tmp2);
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].d = 0x3f3f3f3f;
    }
    ns[s].d = 0;
    ns[s].in = 1;
    pt.push(s);
    while (pt.size())
    {
        int from = pt.front();
        ns[from].in = 0;
        pt.pop();
        for (int i = 0; i < ns[from].ls.size(); i++)
        {
            int to = ns[from].ls[i].to;
            int dis = ns[from].ls[i].dis;
            if (dis + ns[from].d < ns[to].d)
            {
                ns[to].d = dis + ns[from].d;
                if (ns[to].in == 0)
                {
                    ns[to].in = 1;
                    pt.push(to);
                }
            }
        }
    }
    cout << ns[t].d;
    return 0;
}