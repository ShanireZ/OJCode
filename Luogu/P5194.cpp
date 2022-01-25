#include <iostream>
using namespace std;
int n, c;
long long ans, f[1005], qz[1005];
void dfs(long long tot, int last)
{
    ans = max(ans, tot);
    if (tot + qz[last - 1] <= c)
    {
        ans = max(ans, tot + qz[last - 1]);
        return;
    }
    for (int i = last - 1; i >= 1; i--)
    {
        if (tot + f[i] <= c)
        {
            dfs(tot + f[i], i);
        }
    }
}
int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        qz[i] = f[i] + qz[i - 1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (f[i] <= c)
        {
            dfs(f[i], i);
        }
    }
    cout << ans << endl;
    return 0;
}