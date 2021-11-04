#include <cstdio>
#include <map>
using namespace std;
long long read()
{
    long long ans = 0, t = 1;
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
long long gcd(long long x, long long y)
{
    long long r = x % y;
    while (r)
    {
        x = y, y = r;
        r = x % y;
    }
    return y;
}
map<double, int> m;
int ta, tb;
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        long long a = read(), b = read(), c = read();
        if (a == 0)
        {
            ta++;
        }
        else if (b == 0)
        {
            tb++;
        }
        else
        {
            long long g = gcd(a, b);
            double k = abs((1.0 * a / g) / (1.0 * b / g));
            m[k]++;
        }
    }
    int ans = max(ta, tb);
    for (auto i = m.begin(); i != m.end(); i++)
    {
        ans = max(ans, i->second);
    }
    printf("%d\n", n - ans);
    return 0;
}