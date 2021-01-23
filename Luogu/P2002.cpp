#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
    int gid, dfn, low, in;
    vector<int> to;
};
Node ns[100005];
int cns[100005];
stack<int> stk;
int n, m, pos, gpos;
void tarjan(int now)
{
    ns[now].dfn = ns[now].low = ++pos;
    ns[now].in = 1;
    stk.push(now);
    for (int i = 0; i < ns[now].to.size(); i++)
    {
        int to = ns[now].to[i];
        if (ns[to].dfn == 0)
        {
            tarjan(to);
            ns[now].low = min(ns[now].low, ns[to].low);
        }
        else if (ns[to].in)
        {
            ns[now].low = min(ns[now].low, ns[to].dfn);
        }
    }
    if (ns[now].dfn == ns[now].low)
    {
        int id;
        gpos++;
        do
        {
            id = stk.top();
            ns[id].in = 0;
            stk.pop();
            ns[id].gid = gpos;
        } while (id != now);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != b)
        {
            ns[a].to.push_back(b);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int from = ns[i].gid;
        for (int j = 0; j < ns[i].to.size(); j++)
        {
            int to = ns[ns[i].to[j]].gid;
            if (from != to)
            {
                cns[to] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= gpos; i++)
    {
        if (cns[i] == 0)
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}