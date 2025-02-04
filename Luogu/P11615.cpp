#include <algorithm>
#include <bits/extc++.h>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;
#define ull unsigned long long
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf;
ull rd()
{
    ull x = 0;
    char ch = gc();
    while (!isdigit(ch))
    {
        ch = gc();
    }
    while (isdigit(ch))
    {
        x = x * 10 + (ch ^ 48), ch = gc();
    }
    return x;
}
mt19937 rnd(time(0));
struct hsh
{
    // ull operator()(ull x) const //splitmix64
    // {
    //     x += 0x9e3779b97f4a7c15;
    //     x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    //     x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    //     return x ^ (x >> 31);
    // }
    ull operator()(ull x) const
    {
        static const ull s1 = rnd(), s2 = rnd(), s3 = rnd();
        x += s1;
        x = (x ^ (x >> 33)) * s2;
        x = (x ^ (x >> 30)) * s3;
        return x;
    }
};
__gnu_pbds::gp_hash_table<ull, ull, hsh> v;
ull ans;
int main()
{
    int n = rd();
    for (int i = 1; i <= n; i++)
    {
        ull x = rd(), y = rd();
        ans += v[x] * i, v[x] = y;
    }
    printf("%llu\n", ans);
    return 0;
}