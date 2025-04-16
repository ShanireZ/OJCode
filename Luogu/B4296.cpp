#include <algorithm>
#include <iostream>
using namespace std;
int a[105], dis[105], n;
void dfs(int now)
{
    for (int i = 1; i <= a[now] && i + now <= n; i++)
    {
        if (dis[now + i] > dis[now] + 1)
        {
            dis[now + i] = dis[now] + 1;
            dfs(now + i);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    fill(dis + 1, dis + 1 + n, 1e9);
    dis[1] = 0, dfs(1);
    cout << dis[n] << endl;
    return 0;
}