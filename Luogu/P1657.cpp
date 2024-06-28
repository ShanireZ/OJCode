#include <algorithm>
#include <iostream>
using namespace std;
int vis[25], lk[25][2], res, n;
void dfs(int now)
{
    if (now > n)
    {
        res++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && (lk[now][1] == i || lk[now][0] == i))
        {
            vis[i] = 1;
            dfs(now + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lk[i][0] >> lk[i][1];
    }
    dfs(1);
    cout << res << endl;
    return 0;
}