#include <iostream>
#include <vector>
using namespace std;
vector<long long> a[3000005];
int main()
{
    int n, q, s;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        for (int j = 1; j <= s; j++)
        {
            long long x;
            scanf("%lld", &x);
            a[i].push_back(x);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        ans ^= a[x][y - 1];
    }
    printf("%lld", ans);
    return 0;
}