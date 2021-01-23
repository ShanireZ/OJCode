#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    vector<int> ways;
    vector<long long> len;
    int vis;
    long long d[3];
};
Node ns[200005];
queue<int> q;
int t[5], n, m;
long long maxd;
void bfs(int st, int x) //找到距离st最远的点存到t[x+1] 并且更新距离存到ns[i].d[x]中
{
    maxd = 0;
    q.push(st);
    ns[st].vis = 1;
    while (q.size())
    {
        int from = q.front();
        q.pop();
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int to = ns[from].ways[i];
            if (ns[to].vis == 0)
            {
                q.push(to);
                ns[to].vis = 1;
                ns[to].d[x] = ns[from].d[x] + ns[from].len[i];
                if (x == 2) //另一个模式 找到符合题意的点C 到直径两端最短边最大
                {
                    maxd = max(maxd, min(ns[to].d[1], ns[to].d[2]));
                    continue;
                }
                if (ns[to].d[x] > maxd)
                {
                    t[x + 1] = to;
                    maxd = ns[to].d[x];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ns[i].vis = 0;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        ns[u].ways.push_back(v);
        ns[u].len.push_back(w);
        ns[v].ways.push_back(u);
        ns[v].len.push_back(w);
    }
    bfs(1, 0);    //第一轮 找到点1的最远点存到t[x+1]中
    bfs(t[1], 1); //第二轮 找到点t[1]的最远点存到t[x+1]中 更新所有点到t[1]的距离
    bfs(t[2], 2); //第三轮 找到符合题意的点C 更新所有点到t[2]的距离
    cout << maxd + ns[t[1]].d[2];
    return 0;
}