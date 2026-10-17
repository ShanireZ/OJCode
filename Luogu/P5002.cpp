#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> g[10005];
int outd[10005];
int fa[10005];
int dfs(int x)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        int id = g[x][i];
        if (id != fa[x]) //!該邊不是連接的父節點
        {
            fa[id] = x;
            outd[x] += dfs(id); //!得到每個節點的子孫節點個數
        }
    }
    return outd[x];
}
int main()
{
    ios::sync_with_stdio(false);
    int n, r, m;
    cin >> n >> r >> m;
    memset(outd, -1, sizeof(outd));
    outd[r]++;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        outd[x]++;
        outd[y]++; //!統計每個點的出度
    }
    dfs(r); //!從根節點開始遍歷整個樹
    for (int i = 1; i <= m; i++)
    {
        int root;
        cin >> root;
        //!點x為LCA的情況總數 = 以x為第一個點的情況數 + 以x的子孫節點為第一個點的情況數
        //!1.以x為第一個點的情況數 = 樹x節點數目 = x的子孫數 + 1
        //!2.以x的子孫節點為第一個點的情況數 = 每個 (子樹的節點個數 * 樹中非該子樹節點個數)
        //!其中 子樹的節點個數 = 該子樹根節點的子孫節點數 + 1
        //!其中 非該子樹節點個數 = 樹x子孫節點數 - 該子樹根節點的子孫節點數
        int tot = outd[root] + 1;
        for (int i = 0; i < g[root].size(); i++)
        {
            int id = g[root][i];
            if (id != fa[root])
            {
                tot += (outd[id] + 1) * (outd[root] - outd[id]);
            }
        }
        cout << tot << endl;
    }
    return 0;
}