#include <iostream>
using namespace std;
int a[10005], g[10005];
int dfn(int x)
{
    return g[x] = (x == g[x]) ? x : dfn(g[x]);
}
int lowbit(int x)
{
    return x & -x;
}
int main()
{
    long long n, c1, c2;
    cin >> n >> c1 >> c2;
    if (c1 == c2)
    {
        cout << (n - 1) * c1;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[i] = i;
    }
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x = a[i] ^ a[j], trig = (lowbit(x) == x && (x != 0 || n <= 10)) ? 1 : 0;
            if ((c1 < c2 && trig == 1) || (c1 > c2 && trig == 0))
            {
                int gi = dfn(i), gj = dfn(j);
                if (gi != gj)
                {
                    g[gi] = gj, cnt++;
                }
            }
        }
    }
    cout << min(c1, c2) * cnt + max(c1, c2) * (n - 1 - cnt);
    return 0;
}