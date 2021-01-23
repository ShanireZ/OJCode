#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    int vis;
    vector<int> ways;
};
Node nodes[100005];
void dfs(int x)
{
    cout << x << " ";
    nodes[x].vis = 1;
    for (int i = 0; i < nodes[x].ways.size(); i++)
    {
        int nx = nodes[x].ways[i];
        if (nodes[nx].vis == 0)
        {
            dfs(nx);
        }
    }
}
queue<int> q;
void bfs(int start)
{
    nodes[start].vis = 1;
    q.push(start);
    while (q.size() != 0)
    {
        int id = q.front();
        for (int i = 0; i < nodes[id].ways.size(); i++)
        {
            int nid = nodes[id].ways[i];
            if (nodes[nid].vis == 0)
            {
                nodes[nid].vis = 1;
                q.push(nid);
            }
        }
        cout << id << " ";
        q.pop();
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[x].ways.push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(nodes[i].ways.begin(), nodes[i].ways.end());
    }
    dfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        nodes[i].vis = 0;
    }
    bfs(1);
    return 0;
}