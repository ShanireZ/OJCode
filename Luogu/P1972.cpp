#include <cstdio>
#include <algorithm>
using namespace std;
struct Qst
{
    int l, r, id;
    bool operator<(const Qst ano) const
    {
        return r < ano.r;
    }
} qst[1000005]; //所有詢問按r排序
int a[1000005], pos[1000005], last[1000005], ans[1000005];
//a每個位置的值 pos樹狀陣列記錄每個位置是否有新數 last某數字最後一次出現的位置
//數字出現在後方比出現在前方意義更大
int read();
int lowbit(int x)
{
    return x & -x;
}
void edit(int p, int add)
{
    while (p <= 1000000)
    {
        pos[p] += add;
        p += lowbit(p);
    }
}
int query(int p)
{
    int ans = 0;
    while (p)
    {
        ans += pos[p];
        p -= lowbit(p);
    }
    return ans;
}
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
    }
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        qst[i].l = read(), qst[i].r = read();
        qst[i].id = i;
    }
    sort(qst + 1, qst + 1 + m);
    int now = 1;
    for (int i = 1; i <= m; i++)
    {
        while (qst[i].r >= now) //查詢的區間還沒初始化完畢
        {
            if (last[a[now]]) //該數之前出現過 最新一次效用範圍更大
            {
                edit(last[a[now]], -1);
            }
            edit(now, 1);
            last[a[now]] = now;
            now++;
        }
        ans[qst[i].id] = query(qst[i].r) - query(qst[i].l - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
int read()
{
    int ans = 0, t = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
        {
            t = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}