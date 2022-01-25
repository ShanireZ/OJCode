#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int n, vis[20];
struct NL
{
    double x, y;
};
NL nls[20];
double dis[20][20], ans = 1e15;
void dfs(int cnt, double tot, int last)
{
    if (cnt == n)
    {
        ans = min(ans, tot);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 1 || tot + dis[last][i] >= ans)
        {
            continue;
        }
        vis[i] = 1;
        dfs(cnt + 1, tot + dis[last][i], i);
        vis[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nls[i].x >> nls[i].y;
        for (int j = 0; j < i; j++)
        {
            dis[i][j] = dis[j][i] = sqrt(pow((nls[i].x - nls[j].x), 2) + pow((nls[i].y - nls[j].y), 2));
        }
    }
    dfs(0, 0, 0);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}