#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Node
{
    int d, done;    //! d:点s到该点距离 done:是否已经确定最短路径
    vector<int> to; //! 目标点编号
    vector<int> w;  //! 目标点距离权重
};
Node g[10005];
struct Nodeq
{
    int id, w; //! id:更新的点的编号 w:更新的点到s的距离
};
struct cmp
{
    bool operator()(Nodeq a, Nodeq b)
    {
        return a.w > b.w;
    }
};
priority_queue<Nodeq, vector<Nodeq>, cmp> q;
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
    Nodeq st;
    st.id = s, st.w = 0;
    q.push(st);
    while (q.size())
    {
        int from = q.top().id;
        int dfrom = q.top().w;
        q.pop();
        if (g[from].done == 0) //? 如果当前点的最短距离还未确定
        {
            g[from].done = 1;
            for (int i = 0; i < g[from].to.size(); i++)
            {
                int to = g[from].to[i];
                int dto = g[from].w[i];
                if (dto + dfrom < g[to].d)
                {
                    g[to].d = dto + dfrom;
                    Nodeq tmp;
                    tmp.id = to, tmp.w = g[to].d;
                    q.push(tmp);
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