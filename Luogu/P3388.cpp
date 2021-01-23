#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
struct Node
{
    int dfn, low, isg;
    vector<int> way;
};
Node ns[20005];
int pos, root;
void tarjan(int x)
{
    ns[x].dfn = ns[x].low = ++pos;
    int cnt = 0;
    for (int i = 0; i < ns[x].way.size(); i++)
    {
        int id = ns[x].way[i];
        if (ns[id].dfn == 0)
        {
            tarjan(id);
            ns[x].low = min(ns[x].low, ns[id].low);
            if (x != root && ns[id].low >= ns[x].dfn)
            {
                ns[x].isg = 1;
            }
            if (x == root)
            {
                cnt++;
            }
        }
        else
        {
            ns[x].low = min(ns[x].low, ns[id].dfn);
        }
    }
    if (x == root && cnt > 1)
    {
        ns[x].isg = 1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].way.push_back(b);
        ns[b].way.push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            root = i;
            tarjan(i);
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].isg)
        {
            tot++;
        }
    }
    cout << tot << endl;
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].isg)
        {
            cout << i << " ";
        }
    }
    return 0;
}