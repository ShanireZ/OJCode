#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
stack<int> stk;
struct Node
{
    int dfn, low, in;
    vector<int> way;
};
Node ns[10005];
int pos, cnt;
void tarjan(int x)
{
    stk.push(x);
    ns[x].dfn = ns[x].low = ++pos;
    ns[x].in = 1;
    for (int i = 0; i < ns[x].way.size(); i++)
    {
        int id = ns[x].way[i];
        if (ns[id].dfn == 0)
        {
            tarjan(id);
            ns[x].low = min(ns[x].low, ns[id].low);
        }
        else if (ns[id].in)
        {
            ns[x].low = min(ns[x].low, ns[id].dfn);
        }
    }
    if (ns[x].low == ns[x].dfn)
    {
        int id, tot = 0;
        do
        {
            id = stk.top();
            stk.pop();
            tot++;
            ns[id].in = 0;
        } while (id != x);
        if (tot > 1)
        {
            cnt++;
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
        ns[u].way.push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    cout << cnt;
    return 0;
}