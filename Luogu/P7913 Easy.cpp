#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
int read();
struct Plane
{
    int st, ed;
    Plane(int St, int Ed)
    {
        st = St, ed = Ed;
    }
    bool operator<(const Plane ano) const
    {
        return st < ano.st;
    }
};
set<Plane> s;
int t1[100005], t2[100005];
void cnt(int n, int m, int *t)
{
    s.clear();
    for (int i = 1; i <= m; i++)
    {
        int a = read(), b = read();
        s.insert(Plane(a, b));
    }
    for (int i = 1; i <= n; i++) //枚举廊桥
    {
        set<Plane>::iterator p = s.begin();
        while (p != s.end())
        {
            t[i]++;
            int ts = p->ed;
            s.erase(p);
            p = s.lower_bound(Plane(ts, 0));
        }
        t[i] += t[i - 1];
    }
}
int main()
{
    int n = read(), m1 = read(), m2 = read();
    cnt(n, m1, t1);
    cnt(n, m2, t2);
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, t1[i] + t2[n - i]);
    }
    printf("%d\n", ans);
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