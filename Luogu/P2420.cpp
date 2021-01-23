#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
    vector<int> ways;
    vector<int> lens;
    int xr, fa;
};
Node ns[100005];
queue<int> pt;
void bfs(int root)
{
    pt.push(root);
    while (pt.size())
    {
        int from = pt.front();
        pt.pop();
        for (int i = 0; i < ns[from].ways.size(); i++)
        {
            int to = ns[from].ways[i];
            int w = ns[from].lens[i];
            if (to != ns[from].fa)
            {
                ns[to].fa = from;
                ns[to].xr = ns[from].xr ^ w;
                pt.push(to);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ns[u].ways.push_back(v);
        ns[u].lens.push_back(w);
        ns[v].ways.push_back(u);
        ns[v].lens.push_back(w);
    }
    bfs(1);
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << (ns[u].xr ^ ns[v].xr) << endl;
    }
    return 0;
}