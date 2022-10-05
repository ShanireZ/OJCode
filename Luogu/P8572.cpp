#include <cstdio>
#include <map>
#include <vector>
using namespace std;
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
map<pair<int, int>, long long> m;
vector<long long> a[500005];
int main()
{
    int n = read(), k = read(), q = read();
    for (int i = 1; i <= k; i++)
    {
        a[i].push_back(0);
        for (int j = 1; j <= n; j++)
        {
            int x = read();
            a[i].push_back(x);
            a[i][j] += a[i][j - 1];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int l = read(), r = read();
        pair<int, int> p = make_pair(l, r);
        if (m[p] == 0)
        {
            long long x = 0;
            for (int j = 1; j <= k; j++)
            {
                x = max(x, a[j][r] - a[j][l - 1]);
            }
            m[p] = x;
        }
        printf("%lld\n", m[p]);
    }
    return 0;
}