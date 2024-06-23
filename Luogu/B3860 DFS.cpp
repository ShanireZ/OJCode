#include <algorithm>
#include <iostream>
using namespace std;
int a[5005][5005], k[5005], vis[5005], ans, n;
void az(int now)
{
    ans++, vis[now] = 1;
    for (int i = 1; i <= k[now]; i++)
    {
        if (vis[a[now][i]] == 0)
        {
            az(a[now][i]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j];
        }
    }
    az(1);
    cout << ans << endl;
    return 0;
}