#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct Node
{
    int dfn, low, in;
    vector<int> way;
};
Node ns[5005];
vector<int> g[5005];
int pos, gpos;
stack<int> stk;
void tarjan(int x)
{
    ns[x].dfn = ns[x].low = ++pos;
    ns[x].in = 1;
    stk.push(x);
    for (int i = 0; i < ns[x].way.size(); i++)
    {
        int id = ns[x].way[i];
        if (ns[id].dfn == 0)
        {
            tarjan(id);
            ns[x].low = min(ns[x].low, ns[id].low);
        }
        else if (ns[id].in == 1)
        {
            ns[x].low = min(ns[x].low, ns[id].dfn);
        }
    }
    if (ns[x].dfn == ns[x].low)
    {
        int id;
        gpos++;
        do
        {
            id = stk.top();
            stk.pop();
            ns[id].in = 0;
            g[gpos].push_back(id);
        } while (id != x);
        sort(g[gpos].begin(), g[gpos].end());
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        if (t == 1)
        {
            ns[a].way.push_back(b);
        }
        else
        {
            ns[a].way.push_back(b);
            ns[b].way.push_back(a);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    int maxg = 0;
    for (int i = 1; i <= gpos; i++)
    {
        if (g[maxg].size() < g[i].size())
        {
            maxg = i;
        }
        else if (g[maxg].size() == g[i].size())
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (g[maxg][j] > g[i][j])
                {
                    maxg = i;
                    break;
                }
            }
        }
    }
    cout << g[maxg].size() << endl;
    for (int i = 0; i < g[maxg].size(); i++)
    {
        cout << g[maxg][i] << " ";
    }
    return 0;
}