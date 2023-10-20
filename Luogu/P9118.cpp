#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
map<long long, bool> mp;
long long n, k, cnt, c2;
void make()
{
    for (__int128 base = 2; base * base * base <= n; base++)
    {
        __int128 now = base * base, p = 2;
        while (p < k && now < n)
        {
            now *= base, p++;
        }
        if (p != k)
        {
            break;
        }
        while (now <= n)
        {
            if (mp[now] == 0)
            {
                mp[now] = 1, cnt++;
                if (now == (long long)sqrtl(now) * (long long)sqrtl(now))
                {
                    c2++;
                }
            }
            now *= base;
        }
    }
}
int main()
{
    cin >> n >> k;
    if (k == 1)
    {
        cout << n << endl;
    }
    else if (k == 2)
    {
        make();
        cout << (long long)sqrtl(n) + cnt - c2 << endl;
    }
    else
    {
        make();
        cout << cnt + 1 << endl;
    }
    return 0;
}