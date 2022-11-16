#include <iostream>
#include <set>
using namespace std;
#define MX 500005
multiset<int> all, dif;
int st[MX], ed[MX], ans = 0x3f3f3f3f, read();
void update(int x)
{
    auto it = all.lower_bound(x);
    if (it != all.end())
    {
        ans = min(ans, *it - x);
    }
    if (it != all.begin())
    {
        it--;
        ans = min(ans, x - *it);
    }
    all.insert(x);
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        st[i] = ed[i] = x;
        update(x);
    }
    for (int i = 2; i <= n; i++)
    {
        dif.insert(abs(st[i] - ed[i - 1]));
    }
    for (int i = 1; i <= m; i++)
    {
        string op;
        cin >> op;
        if (op[0] == 'I')
        {
            int pos = read(), x = read();
            update(x);
            if (pos != n)
            {
                auto it = dif.lower_bound(abs(ed[pos] - st[pos + 1]));
                dif.erase(it);
                dif.insert(abs(x - st[pos + 1]));
            }
            dif.insert(abs(ed[pos] - x)), ed[pos] = x;
        }
        else if (op[4] == 'G')
        {
            printf("%d\n", *dif.begin());
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
int read()
{
    int ans = 0;
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