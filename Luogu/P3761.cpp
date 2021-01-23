#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Way
{
    int d, tot;
};
Way ways[5005];
struct Node
{
    vector<int> ways;
    int vis, dis[3];
};
Node ns[5005];
queue<int> pt;
int zj, n;
int bfs(int stpos, int chk, int del) //起点 当前未访问点的的vis 当前删除的边的编号
{
    int ans, maxd = -1;
    pt.push(stpos);
    ns[stpos].vis = chk + 1;
    ns[stpos].dis[chk] = 0;
    while (pt.size()) //找直径端点1
    {
        int from = pt.front();
        pt.pop();
        if (ns[from].dis[chk] > maxd)
        {
            ans = from;
            maxd = ns[from].dis[chk];
        }
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int id = ns[from].ways[i];
            if (id == del)
            {
                continue;
            }
            int to = ways[id].tot - from;
            if (ns[to].vis == chk)
            {
                pt.push(to);
                ns[to].dis[chk] = ns[from].dis[chk] + ways[id].d;
                ns[to].vis = chk + 1;
            }
        }
    }
    return ans;
}
int findx(int del) //当前删除的边的编号
{
    int ans[3] = {0};
    for (int i = 1; i <= n; i++) //找到当前树的任意一点
    {
        if (ns[i].vis == 0)
        {
            ans[0] = i;
            break;
        }
    }
    ans[1] = bfs(ans[0], 0, del); //第一个直径端点
    ans[2] = bfs(ans[1], 1, del); //第二个直径端点 更新所有点到端点1距离dis[1]
    bfs(ans[2], 2, del);          //更新所有点到端点2距离dis[2]
    zj = ns[ans[1]].dis[2];       //直径长度
    int maxd = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) //找到直径中点
    {
        if (ns[i].dis[1] + ns[i].dis[2] == zj)
        {
            if (abs(ns[i].dis[1] - ns[i].dis[2]) < maxd)
            {
                ans[0] = i;
                maxd = abs(ns[i].dis[1] - ns[i].dis[2]);
            }
        }
    }
    return ans[0];
}
int main()
{
    cin >> n;
    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> ways[i].d;
        ns[u].ways.push_back(i);
        ns[v].ways.push_back(i);
        ways[i].tot = u + v;
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i < n; i++) //删去每条边
    {
        for (int j = 1; j <= n; j++) //初始化
        {
            ns[j].vis = 0;
        }
        //删边后统计两个区域的直径 和 直径中点
        int x = findx(i), zjx = zj;
        int y = findx(i), zjy = zj;
        int maxd = max(zjx, zjy);
        maxd = max(maxd, ways[i].d + max(ns[x].dis[1], ns[x].dis[2]) + max(ns[y].dis[1], ns[y].dis[2]));
        ans = min(maxd, ans);
    }
    cout << ans;
    return 0;
}
