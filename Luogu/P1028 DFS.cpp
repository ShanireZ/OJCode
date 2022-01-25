#include <iostream>
using namespace std;
int n, ans[1005];
void dfs(int now)
{
    if (ans[now] != 1)
    {
        return;
    }
    for (int i = 1; i <= now / 2; i++)
    {
        dfs(i);
        ans[now] += ans[i];
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = 1;
    }
    dfs(n);
    cout << ans[n] << endl;
    return 0;
}