#include <algorithm>
#include <cstdio>
using namespace std;
#define MX 2000005
struct Quest
{
    int l, r, id;
    bool operator<(const Quest oth) const
    {
        return r < oth.r;
    }
};
Quest qst[MX];
int n, c, m, col[MX], sol[MX], tree[MX], last[MX], llast[MX];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int add)
{
    if (x == 0)
    {
        return;
    }
    while (x <= n)
    {
        tree[x] += add;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int read();
int main()
{
    n = read(), c = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        col[i] = read();
    }
    for (int i = 1; i <= m; i++)
    {
        qst[i].l = read(), qst[i].r = read();
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + m);
    int pos = 1;
    for (int i = 1; i <= m; i++)
    {
        while (qst[i].r >= pos)
        {
            int now = col[pos];
            if (llast[now])
            {
                edit(llast[now], -1);
            }
            llast[now] = last[now], last[now] = pos;
            edit(llast[now], 1);
            pos++;
        }
        sol[qst[i].id] = query(qst[i].r) - query(qst[i].l - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", sol[i]);
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}