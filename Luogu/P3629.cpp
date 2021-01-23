#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Way
{
    int u, v, d, tot;
};
Way ways[100005]; //所有路径
struct Node
{
    vector<int> ways;
    int dis[3], vis, inz;
};
Node ns[100005]; //所有点
queue<int> pt;
int n, k, z1, z2;
int bfs(int stpos, int round)
{
    int maxd = 0, ans = stpos;
    pt.push(stpos);
    ns[stpos].vis = round + 1;
    ns[stpos].dis[round] = 0;
    while (pt.size())
    {
        int from = pt.front();
        pt.pop();
        if (ns[from].dis[round] > maxd)
        {
            ans = from;
            maxd = ns[from].dis[round];
        }
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int id = ns[from].ways[i];
            int to = ways[id].tot - from;
            if (ns[to].vis == round)
            {
                pt.push(to);
                ns[to].vis = round + 1;
                ns[to].dis[round] = ns[from].dis[round] + ways[id].d;
            }
        }
    }
    return ans;
}
int findz() //找到直径
{
    int st[3] = {1, 0, 0};
    st[1] = bfs(st[0], 0);
    st[2] = bfs(st[1], 1);
    bfs(st[2], 2);
    return ns[st[1]].dis[2];
}
//如果两环有重合部分 重合的边在最后会被减两次贡献 多减的贡献需要再补回来
//我们可以将其对第二个环的贡献设置为-1 表示不仅没贡献反而需要多走一遍
void sign(int zj) //标记第一条直径上的边长度为-1
{
    for (int i = 1; i <= n; i++)
    {
        ns[i].inz = 0;
        if (ns[i].dis[1] + ns[i].dis[2] == zj)
        {
            ns[i].inz = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].inz)
        {
            for (int j = 0; j < ns[i].ways.size(); j++)
            {
                int id = ns[i].ways[j];
                int to = ways[id].tot - i;
                if (ns[to].inz)
                {
                    ways[id].d = -1;
                }
            }
        }
    }
}
int ans;
void dp(int x) //dp求修改后的图中直径
{
    ns[x].dis[0] = 0;
    ns[x].vis = 1;
    for (int i = 0; i < ns[x].ways.size(); i++)
    {
        int id = ns[x].ways[i];
        int to = ways[id].tot - x;
        if (ns[to].vis == 0)
        {
            dp(to);
            z2 = max(z2, ns[x].dis[0] + ways[id].d + ns[to].dis[0]);
            ns[x].dis[0] = max(ns[x].dis[0], ns[to].dis[0] + ways[id].d);
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        cin >> ways[i].u >> ways[i].v;
        ways[i].d = 1;
        ways[i].tot = ways[i].u + ways[i].v;
        ns[ways[i].u].ways.push_back(i);
        ns[ways[i].v].ways.push_back(i);
    }
    z1 = findz();
    if (k == 1)
    {
        cout << (n - 1) * 2 + k * 2 - (z1 + 1);
        return 0;
    }
    sign(z1);
    for (int i = 1; i <= n; i++) //清空vis状态
    {
        ns[i].vis = 0;
    }
    dp(1);
    cout << (n - 1) * 2 + k * 2 - (z1 + 1) - (z2 + 1);
    return 0;
}