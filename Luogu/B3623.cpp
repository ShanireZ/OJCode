#include <algorithm>
#include <iostream>
using namespace std;
int a[15], vis[15], n, k;
void dfs(int now)
{
    if (now > k)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        a[now] = i, vis[i] = 1;
        dfs(now + 1);
        vis[i] = 0;
    }
}
int main()
{
    cin >> n >> k;
    dfs(1);
    return 0;
}