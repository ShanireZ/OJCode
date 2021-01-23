#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int inq[100005];         //!SPFA 标记该点是否已在队列中 避免反复添加
int len[100005][2];      //!点1到各点的最短路径 [0]偶数最短路径 [1]奇数最短路径
vector<int> all[100005]; //!所有路径
queue<int> p;            //!SPFA
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        len[i][0] = len[i][1] = 0x3f3f3f3f;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        all[u].push_back(v);
        all[v].push_back(u);
    }
    for (int i = 0; i < all[1].size(); i++)
    {
        int id = all[1][i];
        len[id][1] = 1;
        inq[id] = 1;
        p.push(id);
    }
    while (p.size())
    {
        int from = p.front();
        inq[from] = 0;
        p.pop();
        for (int i = 0; i < all[from].size(); i++)
        {
            int to = all[from][i];
            int trig = 0;
            if (len[to][0] > len[from][1] + 1)
            {
                len[to][0] = len[from][1] + 1;
                trig = 1;
            }
            if (len[to][1] > len[from][0] + 1)
            {
                len[to][1] = len[from][0] + 1;
                trig = 1;
            }
            if (inq[to] == 0 && trig)
            {
                inq[to] = 1;
                p.push(to);
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int a, L;
        cin >> a >> L;
        int t = L % 2;
        if (len[a][t] > L || len[a][t] == 0x3f3f3f3f)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}