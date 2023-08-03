#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 2000005
struct Node
{
    int low, dfn, g;
};
Node ns[MX];
vector<int> to[MX]; // 1~n 真 n+1~2n 假
int read(), pos, gpos, spos, s[MX];
void tarjan(int now)
{
    ns[now].dfn = ns[now].low = ++pos;
    s[++spos] = now;
    for (int nxt : to[now])
    {
        if (ns[nxt].dfn == 0)
        {
            tarjan(nxt);
            ns[now].low = min(ns[now].low, ns[nxt].low);
        }
        else if (ns[nxt].g == 0)
        {
            ns[now].low = min(ns[now].low, ns[nxt].dfn);
        }
    }
    if (ns[now].dfn == ns[now].low)
    {
        gpos++;
        while (now != s[spos])
        {
            ns[s[spos--]].g = gpos;
        }
        ns[s[spos--]].g = gpos;
    }
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read(), a = read(), y = read(), b = read();
        to[x + n * a].push_back(y + n * !b);
        to[y + n * b].push_back(x + n * !a);
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].g == ns[i + n].g)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; i++)
    {
        cout << (ns[i].g < ns[i + n].g) << " ";
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}