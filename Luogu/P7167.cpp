#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define MX 100005
int read(), d[MX], tot[MX], anc[MX][20];
vector<int> to[MX];
stack<int> s;
void dfs(int now)
{
    tot[now] += tot[anc[now][0]];
    for (int nxt : to[now])
    {
        dfs(nxt);
    }
}
int main()
{
    int n = read(), q = read();
    for (int i = 1; i <= n; i++)
    {
        d[i] = read(), tot[i] = read();
        while (s.size() && d[s.top()] < d[i])
        {
            to[i].push_back(s.top()), anc[s.top()][0] = i;
            s.pop();
        }
        s.push(i);
    }
    while (s.size())
    {
        to[0].push_back(s.top()), anc[s.top()][0] = 0;
        s.pop();
    }
    dfs(0);
    for (int j = 1; j < 20; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }
    while (q--)
    {
        int now = read(), v = read();
        for (int j = 19; j >= 0; j--)
        {
            if (anc[now][j] && tot[now] - tot[anc[now][j]] < v)
            {
                v -= tot[now] - tot[anc[now][j]];
                now = anc[now][j];
            }
        }
        printf("%d\n", now);
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