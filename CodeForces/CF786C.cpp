#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
using namespace std;
int a[100005], vis[100005], rec[100005], n, k = 1;
int solve(int lim)
{
    int g = 1, c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[a[i]] == 0)
        {
            if (c == lim)
            {
                while (c)
                {
                    vis[rec[c--]] = 0;
                }
                g++;
            }
            rec[++c] = a[i], vis[a[i]] = 1;
        }
    }
    while (c)
    {
        vis[rec[c--]] = 0;
    }
    return g;
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (k <= n)
    {
        if (k <= pow(n, 0.5))
        {
            cout << solve(k) << ' ';
            k++;
        }
        else
        {
            int g = solve(k), l = k, r = n;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                solve(mid) == g ? l = mid + 1 : r = mid - 1;
            }
            while (k <= r)
            {
                cout << g << ' ';
                k++;
            }
        }
    }
    return 0;
}
// TAG: 枚举 模拟 根号分治 二分