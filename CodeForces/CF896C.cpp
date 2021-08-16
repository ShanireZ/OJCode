#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
struct Block
{
    long long v, t;
    Block(long long V, long long T)
    {
        v = V, t = T;
    }
    bool operator<(const Block oth) const
    {
        return v < oth.v;
    }
};
vector<Block> all;
struct Area
{
    mutable long long l, r, v;
    Area(long long L, long long R, long long V)
    {
        l = L, r = R, v = V;
    }
    bool operator<(const Area oth) const
    {
        return l < oth.l;
    }
};
set<Area> s;
long long n, m, seed, vmax, a[100005];
long long read();
long long rnd()
{
    long long ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}
long long fastPow(long long a, long long b, long long p)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}
set<Area>::iterator split(long long x)
{
    set<Area>::iterator it = s.lower_bound(Area(x, 0, 0));
    if (it != s.end() && it->l == x)
    {
        return it;
    }
    it--;
    long long l = it->l, r = it->r, v = it->v;
    s.erase(it);
    s.insert(Area(l, x - 1, v));
    return s.insert(Area(x, r, v)).first;
}
void edit(long long l, long long r, long long op, long long x)
{
    set<Area>::iterator itr = split(r + 1);
    set<Area>::iterator itl = split(l);
    if (op == 1)
    {
        while (itl != itr)
        {
            itl->v += x;
            itl++;
        }
    }
    else
    {
        s.erase(itl, itr);
        s.insert(Area(l, r, x));
    }
}
long long query(long long l, long long r, long long op, long long x, long long y = 0)
{
    set<Area>::iterator itr = split(r + 1);
    set<Area>::iterator itl = split(l);
    long long ans = 0;
    if (op == 3)
    {
        all.clear();
        while (itl != itr)
        {
            long long l = itl->l, r = itl->r, v = itl->v;
            all.push_back(Block(v, r - l + 1));
            itl++;
        }
        sort(all.begin(), all.end());
        long long cnt = 0;
        for (int i = 0; i < all.size(); i++)
        {
            cnt += all[i].t;
            if (cnt >= x)
            {
                ans = all[i].v;
                break;
            }
        }
    }
    else
    {
        while (itl != itr)
        {
            long long l = itl->l, r = itl->r, v = itl->v;
            ans = (ans + fastPow(v % y, x, y) * (r - l + 1)) % y;
            itl++;
        }
    }
    return ans;
}
int main()
{
    n = read(), m = read(), seed = read(), vmax = read();
    s.insert(Area(1, n, 0));
    for (int i = 1; i <= n; i++)
    {
        a[i] = (rnd() % vmax) + 1;
        edit(i, i, 2, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        long long op = (rnd() % 4) + 1;
        long long l = (rnd() % n) + 1;
        long long r = (rnd() % n) + 1;
        if (l > r)
        {
            swap(l, r);
        }
        if (op == 1)
        {
            long long x = (rnd() % vmax) + 1;
            edit(l, r, op, x);
        }
        else if (op == 2)
        {
            long long x = (rnd() % vmax) + 1;
            edit(l, r, op, x);
        }
        else if (op == 3)
        {
            long long x = (rnd() % (r - l + 1)) + 1;
            printf("%lld\n", query(l, r, op, x));
        }
        else
        {
            long long x = (rnd() % vmax) + 1;
            long long y = (rnd() % vmax) + 1;
            printf("%lld\n", query(l, r, op, x, y));
        }
    }
}
long long read()
{
    long long ans = 0, t = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * t;
}