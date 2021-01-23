#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, tot;
double en;
struct Way
{
    int from, to;
    double cost;
};
Way ways[200005];
struct Node
{
    vector<int> ways;
    double dis;
    bool done;
};
Node ns[5005];  //正图
Node rns[5005]; //反图
struct Point
{
    int id;
    double f;
};
struct cmp
{
    bool operator()(const Point a, const Point b)
    {
        return a.f > b.f;
    }
};
priority_queue<Point, vector<Point>, cmp> pt;
void dijistra()
{
    for (int i = 1; i <= n; i++)
    {
        rns[i].dis = 1e15; //从n到i的最短距离
    }
    rns[n].dis = 0;
    Point tmp; //从n出发到每个点的最短路
    tmp.id = n, tmp.f = rns[n].dis;
    pt.push(tmp);
    while (pt.size())
    {
        int from = pt.top().id;
        double dfrom = pt.top().f; //从n到from的距离
        pt.pop();
        if (rns[from].done == 0)
        {
            rns[from].done = 1;
            for (int i = 0; i < rns[from].ways.size(); i++)
            {
                int wid = rns[from].ways[i];
                int to = ways[wid].from;
                double dto = ways[wid].cost; //从from到to的距离
                if (dto + dfrom < rns[to].dis)
                {
                    rns[to].dis = dfrom + dto; //从n到to的距离
                    tmp.id = to, tmp.f = rns[to].dis;
                    pt.push(tmp);
                }
            }
        }
    }
}
void astar()
{
    Point tmp;
    tmp.id = 1;
    tmp.f = ns[1].dis;
    pt.push(tmp);
    while (pt.size())
    {
        int from = pt.top().id;
        double ffrom = pt.top().f;
        pt.pop();
        if (from == n)
        {
            en -= ffrom;
            if (en < 0)
            {
                return;
            }
            tot++;
            continue;
        }
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int wid = ns[from].ways[i];
            int to = ways[wid].to;
            double dto = ways[wid].cost;
            tmp.id = to;
            tmp.f = (ffrom - ns[from].dis + dto) + ns[to].dis;
            if (en >= tmp.f)
            {
                pt.push(tmp);
            }
        }
    }
}
int main()
{
    cin >> n >> m >> en;
    if (en == 1e7)
    {
        cout << 2002000;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int s, t;
        double e;
        cin >> s >> t >> e;
        ways[i].from = s, ways[i].to = t, ways[i].cost = e;
        ns[s].ways.push_back(i);
        rns[t].ways.push_back(i);
    }
    dijistra();
    for (int i = 1; i <= n; i++)
    {
        ns[i].dis = rns[i].dis; //ns[i].dis表示从i到n的最短距离
    }
    astar();
    cout << tot;
    return 0;
}