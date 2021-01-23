#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
struct Line
{
    int tar, w;
};
struct Point
{
    int id, d;
};
struct cmp
{
    bool operator()(Point a, Point b)
    {
        return a.d > b.d;
    }
};
vector<Line> g[100005];
int vis[100005], dis[100005];
priority_queue<Point, vector<Point>, cmp> p;
int main()
{
    ios::sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Line tmp;
        tmp.tar = v, tmp.w = w;
        g[u].push_back(tmp);
    }
    fill(dis + 1, dis + 1 + n, INT_MAX);
    dis[s] = 0;
    Point tmp;
    tmp.d = 0, tmp.id = s;
    p.push(tmp);
    while (p.size())
    {
        int from = p.top().id;
        p.pop();
        if (vis[from] == 0)
        {
            vis[from] = 1;
            for (int i = 0; i < g[from].size(); i++)
            {
                int to = g[from][i].tar;
                int d = g[from][i].w;
                if (vis[to] == 0 && dis[to] > dis[from] + d)
                {
                    dis[to] = dis[from] + d;
                    //*血泪，想了一天才想通的问题 错误示范在后面
                    //todo务必要用存两个数据的优先队列，一个是ID，一个是距离
                    //!如果用只存ID优先队列，可能会造成更新后PUSH进去的ID被之前上层的同ID卡住，而不能继续向上:
                    //!因为是插入而不是重构，所以之前的ID只会值更新而不会移动，堆的结构已经被破坏掉了
                    //!如果新PUSH的和之前的同号的在同一边，必然会在上升中被卡住，有可能不能到达正确位置，除非堆重构
                    //todo用两个数据的优先队列,那么相同的ID里面的距离会不同，新PUSH的距离较小，肯定能到达正确位置
                    //todo之前队伍里的ID就无所谓了，必然之前已经标记为访问过了，肯定不会再访问
                    //?之前已经访问过的点为何不用再更新了？因为再走一遍就等同于A-B(OK) A-B-C-B(再走一遍)，绕路必然更远
                    Point tmp;
                    tmp.id = to, tmp.d = dis[to];
                    p.push(tmp);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <climits>
// #include <queue>
// #include <algorithm>
// using namespace std;
// struct Line
// {
//     int tar, w;
// };
// vector<Line> g[100005];
// int vis[100005], dis[100005];
// struct cmp
// {
//     bool operator()(int a, int b)
//     {
//         return dis[a] > dis[b];
//     }
// };
// priority_queue<int, vector<int>, cmp> p;
// int main()
// {
//     ios::sync_with_stdio(false);
//     int n, m, s;
//     cin >> n >> m >> s;
//     for (int i = 1; i <= m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         Line tmp;
//         tmp.tar = v, tmp.w = w;
//         g[u].push_back(tmp);
//     }
//     fill(dis + 1, dis + 1 + n, INT_MAX);
//     dis[s] = 0;
//     p.push(s);
//     while (p.size())
//     {
//         int from = p.top();
//         p.pop();
//         if (vis[from] == 0)
//         {
//             vis[from] = 1;
//             for (int i = 0; i < g[from].size(); i++)
//             {
//                 int to = g[from][i].tar;
//                 int d = g[from][i].w;
//                 if (vis[to] == 0 && dis[to] > dis[from] + d)
//                 {
//                     dis[to] = dis[from] + d;
//                     p.push(to);
//                 }
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cout << dis[i] << " ";
//     }
//     return 0;
// }