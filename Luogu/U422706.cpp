#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node
{
    int p, v;
    bool operator<(const Node &oth) const
    {
        return v > oth.v;
    }
};
vector<Node> b[1005];
int n, t[1005], bc[1005], gc[1005], g[1005][1005];
queue<int> q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int v;
            cin >> v;
            b[i].push_back(Node{j, v});
        }
        sort(b[i].begin(), b[i].end());
        q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    while (q.size())
    {
        int nb = q.front();
        q.pop();
        if (t[nb] == n)
        {
            continue;
        }
        int ng = b[nb][t[nb]].p;
        if (gc[ng] == 0)
        {
            gc[ng] = nb, bc[nb] = ng;
        }
        else if (g[ng][nb] > g[ng][gc[ng]])
        {
            q.push(gc[ng]), t[gc[ng]]++;
            bc[nb] = ng, gc[ng] = nb;
        }
        else
        {
            q.push(nb), t[nb]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << bc[i] << " ";
    }
    return 0;
}