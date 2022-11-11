#include <cstdio>
#include <set>
using namespace std;
set<int> s; // 存价格
int col[1000005];
int read();
int main()
{
    int opt = read();
    long long tw = 0, tc = 0;
    while (opt != -1)
    {
        if (opt == 1)
        {
            int w = read(), c = read();
            if (col[c] == 0)
            {
                tc += c, tw += w, col[c] = w, s.insert(c);
            }
        }
        else if (opt == 2)
        {
            if (s.size())
            {
                auto it = --s.end();
                tc -= *it, tw -= col[*it], col[*it] = 0;
                s.erase(it);
            }
        }
        else
        {
            if (s.size())
            {
                auto it = s.begin();
                tc -= *it, tw -= col[*it], col[*it] = 0;
                s.erase(s.begin());
            }
        }
        opt = read();
    }
    printf("%lld %lld\n", tw, tc);
    return 0;
}
int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}