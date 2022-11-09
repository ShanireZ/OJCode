#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int fa, v;
    vector<int> ch;
};
Node ns[100005];
struct Way
{
    int x, y;
};
Way ways[100005];
int val[100005];
void dfs(int id)
{
    for (int i = 0; i < ns[id].ch.size(); i++)
    {
        int to = ns[id].ch[i];
        if (to == ns[id].fa)
        {
            continue;
        }
        ns[to].fa = id;
        dfs(to);
        ns[id].v += ns[to].v;
    }
}
void edit(int id, int add)
{
    ns[id].v += add;
    while (ns[id].fa)
    {
        id = ns[id].fa;
        ns[id].v += add;
    }
}
void cut(int wid)
{
    int a = ways[wid].x;
    int b = ways[wid].y;
    if (ns[a].fa == b)
    {
        ns[a].fa = 0;
        ns[b].v -= ns[a].v;
        while (ns[b].fa)
        {
            b = ns[b].fa;
            ns[b].v -= ns[a].v;
        }
    }
    else if (ns[b].fa == a)
    {
        ns[b].fa = 0;
        ns[a].v -= ns[b].v;
        while (ns[a].fa)
        {
            a = ns[a].fa;
            ns[a].v -= ns[b].v;
        }
    }
}
void query(int id)
{
    while (ns[id].fa)
    {
        id = ns[id].fa;
    }
    cout << ns[id].v << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        ns[i].v = val[i];
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].ch.push_back(b);
        ns[b].ch.push_back(a);
        ways[i].x = a, ways[i].y = b;
    }
    dfs(1);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            cut(x);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            int add = y - val[x];
            val[x] = y;
            edit(x, add);
        }
        else if (op == 3)
        {
            cin >> x;
            query(x);
        }
    }
    return 0;
}