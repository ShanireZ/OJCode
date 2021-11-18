#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int read();
int pen[150000], lastc[150000], opt[150000], cnt[1000005], blk;
//pen所有画笔 cnt不同颜色个数 blk块大小 lastc最后一次的颜色 opt离线答案
struct Change
{
    int pos, nv, ov;
    Change(int Pos = 0, int Nv = 0, int Ov = 0)
    {
        pos = Pos, nv = Nv, ov = Ov;
    }
};
Change change[150000];
struct Quer
{
    int t, l, r, id;
    Quer(int T = 0, int L = 0, int R = 0, int Id = 0)
    {
        t = T, l = L, r = R, id = Id;
    }
};
bool cmpb(Quer a, Quer b)
{
    if (a.l / blk == b.l / blk)
    {
        if (a.r / blk == b.r / blk)
        {
            return a.t < b.t;
        }
        return a.r / blk < b.r / blk;
    }
    return a.l / blk < b.l / blk;
}
Quer quer[200005]; //所有询问
int main()
{
    int n = read(), m = read(), cpos = 0, qpos = 0;
    for (int i = 1; i <= n; i++)
    {
        pen[i] = read();
        lastc[i] = pen[i];
    }
    for (int i = 1; i <= m; i++)
    {
        char op = getchar();
        while (op != 'Q' && op != 'R')
        {
            op = getchar();
        }
        if (op == 'Q')
        {
            int l = read(), r = read();
            quer[qpos] = Quer(cpos, l, r, ++qpos);
        }
        else
        {
            int p = read(), c = read();
            change[++cpos] = Change(p, c, lastc[p]);
            lastc[p] = c;
        }
    }
    blk = pow(n, 0.66667);
    sort(quer + 1, quer + 1 + qpos, cmpb);
    int nl = 1, nr = 0, nt = 0, ans = 0;
    for (int i = 1; i <= qpos; i++)
    {
        int l = quer[i].l, r = quer[i].r, t = quer[i].t;
        while (nl < l)
        {
            ans -= !--cnt[pen[nl++]];
        }
        while (nl > l)
        {
            ans += !cnt[pen[--nl]]++;
        }
        while (nr < r)
        {
            ans += !cnt[pen[++nr]]++;
        }
        while (nr > r)
        {
            ans -= !--cnt[pen[nr--]];
        }
        while (nt < t)
        {
            nt++;
            pen[change[nt].pos] = change[nt].nv;
            if (change[nt].pos <= nr && change[nt].pos >= nl)
            {
                ans += !cnt[change[nt].nv]++;
                ans -= !--cnt[change[nt].ov];
            }
        }
        while (nt > t)
        {
            pen[change[nt].pos] = change[nt].ov;
            if (change[nt].pos <= nr && change[nt].pos >= nl)
            {
                ans -= !--cnt[change[nt].nv];
                ans += !cnt[change[nt].ov]++;
            }
            nt--;
        }
        opt[quer[i].id] = ans;
    }
    for (int i = 1; i <= qpos; i++)
    {
        printf("%d\n", opt[i]);
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
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}