#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
int n, root, max_deep, max_wide;
struct Node
{
    int deep;
    int anc[10];
    vector<int> childs;
};
Node nodes[105];
queue<Node> p;
void make_deep(int node_id)
{
    p.push(nodes[node_id]);
    int tot = 0, cur = 0;
    while (p.size() > 0)
    {
        Node tmp = p.front();
        if (cur == tmp.deep)
        {
            tot++;
        }
        else
        {
            max_deep = max(max_deep, tmp.deep);
            max_wide = max(max_wide, tot);
            cur = tmp.deep;
            tot = 1;
        }
        for (int i = 0; i < tmp.childs.size(); i++)
        {
            nodes[tmp.childs[i]].deep = tmp.deep + 1;
            p.push(nodes[tmp.childs[i]]);
        }
        p.pop();
    }
    max_wide = max(max_wide, tot);
}
void make_anc()
{
    for (int i = 1; pow(2, i) <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nodes[j].anc[i] = nodes[nodes[j].anc[i - 1]].anc[i - 1];
        }
    }
}
int get_lca(int a, int b)
{
    if (nodes[a].deep < nodes[b].deep)
    {
        swap(a, b);
    }
    int gap = 0;
    while (pow(2, gap) < nodes[a].deep)
    {
        gap++;
    }
    gap--;
    for (int i = gap; i >= 0; i--)
    {
        if (nodes[a].deep - pow(2, i) >= nodes[b].deep)
        {
            a = nodes[a].anc[i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = gap; i >= 0; i--)
    {
        if (nodes[a].anc[i] != nodes[b].anc[i])
        {
            a = nodes[a].anc[i];
            b = nodes[b].anc[i];
        }
    }
    return nodes[a].anc[0];
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nodes[y].anc[0] = x;
        nodes[x].childs.push_back(y);
    }
    root = 1;
    nodes[root].deep = 1;
    make_deep(root);
    make_anc();
    int u, v;
    cin >> u >> v;
    int len = 2 * nodes[u].deep + nodes[v].deep - 3 * nodes[get_lca(u, v)].deep;
    cout << max_deep << endl
         << max_wide << endl
         << len;
    return 0;
}