#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    int sign;
    vector<int> way;
};
Node nodes[10005];
int trig, tot0, tot1;
int maxn, minn;
void dfs(int x)
{
    for (int i = 0; i < nodes[x].way.size(); i++)
    {
        int id = nodes[x].way[i];
        if (nodes[id].sign == -1)
        {
            nodes[id].sign = !nodes[x].sign;
            if (nodes[id].sign == 0)
            {
                tot0++;
            }
            else
            {
                tot1++;
            }
            dfs(id);
        }
        else if (nodes[id].sign == nodes[x].sign)
        {
            cout << "Impossible";
            trig = 1;
        }
        if (trig)
        {
            return;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        nodes[u].way.push_back(v);
        nodes[v].way.push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        nodes[i].sign = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].way.size() == 0)
        {
            continue;
        }
        if (nodes[i].sign == -1)
        {
            tot0 = 1, tot1 = 0;
            nodes[i].sign = 0;
            dfs(i);
            maxn += max(tot0, tot1);
            minn += min(tot0, tot1);
            if (trig)
            {
                return 0;
            }
        }
    }
    cout << minn;
    return 0;
}