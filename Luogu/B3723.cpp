#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
multiset<long long> s;
long long read(), a, b;
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        s.insert(read());
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            auto pos = s.upper_bound(a);
            if (pos != s.begin())
            {
                pos--;
            }
            a += *pos, s.erase(pos);
        }
        else
        {
            auto pos = s.upper_bound(b);
            if (pos != s.begin())
            {
                pos--;
            }
            b += *pos, s.erase(pos);
        }
    }
    printf("%lld %lld\n", a, b);
    return 0;
}
long long read()
{
    long long ans = 0;
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