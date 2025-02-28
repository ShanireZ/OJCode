#include <algorithm>
#include <iostream>
using namespace std;
char *p1, *p2, buf[1 << 20];
inline char gc()
{
    if (p1 == p2)
        p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin);
    return p1 == p2 ? ' ' : *p1++;
}
inline long long read()
{
    register long long s = 0;
    register char c = gc();
    while (c < '0' || c > '9')
        c = gc();
    while (c >= '0' && c <= '9')
        s = (s << 3) + (s << 1) + (c ^ 48), c = gc();
    return s;
}
int ns[100];
int main()
{
    long long T = read();
    while (T--)
    {
        long long k = read(), x = read();
        if (x >= (1ll << k) || x < (1ll << (k - 1)))
        {
            putchar('0');
            continue;
        }
        int ok = 1, c = 0, pos = 0;
        while (x > 1)
        {
            ns[++pos] = x % 2;
            x /= 2;
            if (ns[pos] == 0 && c % 2 == 1)
            {
                ok = 0;
                break;
            }
            c = (ns[pos] ? c + 1 : 0);
        }
        (ok && c % 2 == 0) ? putchar('1') : putchar('0');
    }
    return 0;
}