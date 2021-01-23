#include <cstdio>
#include <map>
using namespace std;
long long read();
map<long long, int> t;
int main()
{
    int n = read();
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long a = read();
        long long b = read() ^ a;
        t[a]++;
        if (t[ans] < t[a] || t[ans] == t[a] && ans > a)
        {
            ans = a;
        }
        if (a != b)
        {
            t[b]++;
            if (t[ans] < t[b] || t[ans] == t[b] && ans > b)
            {
                ans = b;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
long long read() //快读
{
    char ch = getchar();
    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }
    long long t = 1, n = 0;
    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * t;
}