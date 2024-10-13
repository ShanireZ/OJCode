#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int ed, sl;
    bool operator<(const Node &oth) const
    {
        return ed > oth.ed;
    }
};
priority_queue<Node> cpt[200005];
int n, m, v[200005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        while (cpt[b].size() && cpt[b].top().ed <= a)
        {
            v[b] += cpt[b].top().sl;
            cpt[b].pop();
        }
        if (v[b] >= d)
        {
            v[b] -= d, cpt[b].emplace(Node{a + c, d});
            cout << v[b] << '\n';
        }
        else
        {
            cout << "-1\n";
        }
    }
    return 0;
}