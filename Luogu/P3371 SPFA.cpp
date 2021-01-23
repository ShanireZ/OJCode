#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node
{
    //! t:该点加入队列次数 d:点s到该点距离 inq:该点当前是否在队列里
    int t, d, inq;
    vector<int> to; //! 目标点编号
    vector<int> w;  //! 目标点距离权重
};
Node g[10005];
queue<int> q;
int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        g[i].d = INT_MAX;
    }
    g[s].d = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].to.push_back(v);
        g[u].w.push_back(w);
    }
    q.push(s);
    while (q.size())
    {
        int from = q.front();
        g[from].inq = 0; //? 从队列删除
        q.pop();
        for (int i = 0; i < g[from].to.size(); i++) //? 遍历队首直连点
        {
            int to = g[from].to[i], dis = g[from].w[i];
            if (dis + g[from].d < g[to].d) //? 需要更新最短路径
            {
                g[to].d = dis + g[from].d;
                if (g[to].inq == 0) //? 未在队列中加入队列
                {
                    g[to].inq = 1;
                    g[to].t++;
                    q.push(to);
                    if (g[to].t > n) //? 存在负环
                    {
                        cout << INT_MAX;
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << g[i].d << " ";
    }
    return 0;
}