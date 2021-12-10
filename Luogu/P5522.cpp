#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
char s[35];
int n, m, q, ans, tree[2][31][100010], tp[100010][31];
inline int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
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
inline int lowbit(int x)
{
    return x & -x;
}
inline void edit(int type, int cpos, int spos, int ex)
{
    while (spos <= m)
    {
        tree[type][cpos][spos] += ex;
        spos += lowbit(spos);
    }
}
inline int query(int type, int cpos, int spos)
{
    int ans = 0;
    while (spos)
    {
        ans += tree[type][cpos][spos];
        spos -= lowbit(spos);
    }
    return ans;
}
int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++)
        {
            tp[i][j] = s[j] - '0';
            if (tp[i][j] <= 1)
            {
                edit(tp[i][j], j, i, 1);
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int op = read();
        if (op == 0) // 查询
        {
            int l = read(), r = read(), now = 1;
            for (int j = 1; j <= n; j++)
            {
                int cnt0 = query(0, j, r) - query(0, j, l - 1), cnt1 = query(1, j, r) - query(1, j, l - 1);
                if (cnt0 > 0 && cnt1 > 0)
                {
                    now = 0;
                    break;
                }
                if (cnt0 == 0 && cnt1 == 0)
                {
                    now <<= 1;
                }
            }
            ans ^= now;
        }
        else // 修改
        {
            int spos = read();
            scanf("%s", s + 1);
            for (int j = 1; j <= n; j++)
            {
                if (tp[spos][j] == s[j] - '0')
                {
                    continue;
                }
                if (tp[spos][j] <= 1)
                {
                    edit(tp[spos][j], j, spos, -1);
                }
                tp[spos][j] = min(s[j] - '0', 2);
                if (tp[spos][j] <= 1)
                {
                    edit(tp[spos][j], j, spos, 1);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}