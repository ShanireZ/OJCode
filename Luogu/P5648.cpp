#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define MX 500005
long long a[MX], tot[MX], lastans;
int pw[20], st[MX][20], read();
vector<int> chs[MX];
stack<int> s;
void dfs(int now, int fa)
{
    tot[now] = tot[fa] + (fa - now) * a[now];
    for (int ch : chs[now])
    {
        dfs(ch, now);
    }
}
int main()
{
    int n = read(), t = read();
    for (int i = 1; i <= n; i++)
    {
        st[i][0] = i, a[i] = read();
        while (s.size() && a[s.top()] < a[i])
        {
            chs[i].push_back(s.top()), s.pop();
        }
        s.push(i);
    }
    while (s.size())
    {
        chs[0].push_back(s.top()), s.pop();
    }
    dfs(0, 0);
    pw[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        pw[i] = pw[i - 1] * 2;
        for (int j = 1; j + pw[i] - 1 <= n; j++)
        {
            st[j][i] = (a[st[j][i - 1]] >= a[st[j + pw[i - 1]][i - 1]] ? st[j][i - 1] : st[j + pw[i - 1]][i - 1]);
        }
    }
    while (t--)
    {
        int l = 1 + (read() ^ lastans) % n;
        int q = 1 + (read() ^ (lastans + 1)) % (n - l + 1);
        int p = log2(q);
        p = (a[st[l][p]] >= a[st[l + q - pw[p]][p]] ? st[l][p] : st[l + q - pw[p]][p]);
        lastans = tot[l] - tot[p] + a[p] * (l + q - p);
        printf("%lld\n", lastans);
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
// TAG: ST表 倍增 树上差分 树上前缀和 树上两点距离 树上DP