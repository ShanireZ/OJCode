#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
long long sz[100005];
int main()
{
    long long n, root = 1, ans = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        sz[u]++, sz[v]++;
    }
    sz[root]++;
    for (int i = 1; i <= n; i++)
    {
        if (sz[i] == 0)
        {
            continue;
        }
        long long cost = ceil(log2(sz[i])) + (sz[i] - 1);
        ans += cost;
    }
    cout << ans;
    return 0;
}