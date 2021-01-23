#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
//#include <fstream>
using namespace std;
int buy[3005];
struct Node
{
    int dfn, low, in, g;
    vector<int> way;
};
Node ns[3005];
struct Block
{
    int price, ind;
    vector<int> way;
    vector<int> ch;
};
Block blk[3005];
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
            blk[gpos].ch.push_back(id);
        } while (x != id);
    }
}

int main()
{
    //freopen("111.in", "r", stdin);
    int n;
    cin >> n;
    int p;
    cin >> p;
    for (int i = 1; i <= p; i++)
    {
        int id, price;
        cin >> id >> price;
        buy[id] = price;
    }
    int r;
    cin >> r;
    for (int i = 1; i <= r; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].way.push_back(b);
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
        int id = ns[i].g;
        if (blk[id].price == 0)
        {
            blk[id].price = buy[i];
        }
        else if (buy[i] != 0)
        {
            blk[id].price = min(buy[i], blk[id].price);
        }
        for (int j = 0; j < ns[i].way.size(); j++)
        {
            int to = ns[ns[i].way[j]].g;
            if (id != to)
            {
                blk[id].way.push_back(to);
            }
        }
    }
    for (int i = 1; i <= gpos; i++)
    {
        sort(blk[i].way.begin(), blk[i].way.end());
        blk[i].way.erase(unique(blk[i].way.begin(), blk[i].way.end()), blk[i].way.end());
        for (int j = 0; j < blk[i].way.size(); j++)
        {
            int to = blk[i].way[j];
            blk[to].ind++;
        }
    }
    int trig = 1, ans = 5000, ansp = 0;
    for (int i = 1; i <= gpos; i++)
    {
        if (blk[i].price == 0 && blk[i].ind == 0)
        {
            trig = 0;
            for (int j = 0; j < blk[i].ch.size(); j++)
            {
                ans = min(ans, blk[i].ch[j]);
            }
        }
        else if (blk[i].ind == 0)
        {
            ansp += blk[i].price;
        }
    }
    if (trig) //能控制
    {
        cout << "YES" << endl
             << ansp;
    }
    else
    {
        cout << "NO" << endl
             << ans;
    }
    return 0;
}