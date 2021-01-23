#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Way
{
    int tot, d;
};
Way ways[5005]; //所有边
struct Node
{
    int done, d;
    vector<int> ws;
};
Node ns[105]; //所有点
struct Line   //优先队列专用
{
    int to, d;
    bool operator<(Line x) const
    {
        return d > x.d;
    }
};
priority_queue<Line> pt;
int n, m, prew[105]; //每个点在最短路上的前方点
vector<int> roadmap; //组成初始状态最短路的所有边
void djikstra()
{
    for (int i = 1; i <= n; i++)
    {
        ns[i].d = INT_MAX;
        ns[i].done = 0;
    }
    ns[1].d = 0;
    Line tmp;
    tmp.d = 0, tmp.to = 1;
    pt.push(tmp);
    while (pt.size())
    {
        int from = pt.top().to;
        int dfrom = pt.top().d;
        pt.pop();
        if (ns[from].done == 1)
        {
            continue;
        }
        ns[from].done = 1;
        for (int i = 0; i < ns[from].ws.size(); i++)
        {
            int wid = ns[from].ws[i];
            int to = ways[wid].tot - from;
            int dto = ways[wid].d;
            if (dto + dfrom < ns[to].d)
            {
                ns[to].d = dto + dfrom;
                prew[to] = wid;
                tmp.d = dfrom + dto;
                tmp.to = to;
                pt.push(tmp);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        ways[i].tot = a + b;
        ways[i].d = l;
        ns[a].ws.push_back(i);
        ns[b].ws.push_back(i);
    }
    djikstra();
    int st = ns[n].d, maxadd = 0;
    int pos = n;
    while (prew[pos] != 0)
    {
        int wid = prew[pos];
        roadmap.push_back(wid);
        pos = ways[wid].tot - pos;
    }
    //稻草放在最短路上才有可能增大最短路长度
    //枚举最短路上的每条边 试着扩大 不要忘记回溯
    for (int i = 0; i < roadmap.size(); i++)
    {
        int wid = roadmap[i];
        ways[wid].d *= 2;
        djikstra();
        maxadd = max(maxadd, ns[n].d - st);
        ways[wid].d /= 2;
    }
    cout << maxadd;
    return 0;
}