#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Node
{
    int gid, low, dfn, in;
    vector<int> to;
};
Node ns[205];
int cns[205]; //每个强连通的入度
int n, pos, gpos;
stack<int> stk;
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
            stk.pop();
            ns[id].in = 0;
            ns[id].gid = gpos;
        } while (id != now);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tar;
        cin >> tar;
        while (tar != 0)
        {
            ns[i].to.push_back(tar);
            cin >> tar;
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
            if (to != from) //两点不在同一强连通内
            {
                cns[to] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= gpos; i++) //寻找入度为0的强连通
    {
        if (cns[i] == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}