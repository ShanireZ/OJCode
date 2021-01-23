#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
struct Area
{
    int ind, otd;
    vector<int> way;
};
Area area[105];
struct Node
{
    int dfn, low, in, g;
    vector<int> way;
};
Node ns[105];
stack<int> stk;
int pos, gpos;
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
            ns[id].g = gpos;
        } while (id != x);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (x != 0)
        {
            ns[i].way.push_back(x);
            cin >> x;
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
        int from = ns[i].g;
        for (int j = 0; j < ns[i].way.size(); j++)
        {
            int to = ns[ns[i].way[j]].g;
            if (from != to)
            {
                area[from].otd++;
                area[to].ind++;
            }
        }
    }
    int in0 = 0, ot0 = 0;
    for (int i = 1; i <= gpos; i++)
    {
        if (area[i].ind == 0)
        {
            in0++;
        }
        if (area[i].otd == 0)
        {
            ot0++;
        }
    }
    cout << in0 << endl;
    if (gpos == 1)
    {
        cout << 0;
    }
    else
    {
        cout << max(in0, ot0);
    }
    return 0;
}