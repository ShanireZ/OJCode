#include <iostream>
#include <algorithm>
using namespace std;
int a[10], b[10], ans[10], usd[10];
int n, k, trig;
void dfs(int step)
{
    if (step > k)
    {
        trig = 1;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (usd[i] == 1 || a[i] < b[step])
        {
            continue;
        }
        usd[i] = 1;
        ans[step] = i;
        dfs(step + 1);
        usd[i] = 0;
        if (trig == 1)
        {
            return;
        }
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    dfs(1);
    if (trig == 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= k; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}