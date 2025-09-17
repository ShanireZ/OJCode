#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, ans, l[25][25], ok[25];
void f(int now, int sum)
{
    ok[now] = 1, ans = max(ans, sum);
    for (int i = 1; i <= n; i++)
    {
        if (ok[i] == 0 && l[now][i] != -1)
        {
            sum += l[now][i];
            f(i, sum);
            sum -= l[now][i];
        }
    }
    ok[now] = 0;
}
int main()
{
    memset(l, -1, sizeof(l));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        l[a][b] = l[b][a] = max(l[a][b], c);
    }
    for (int i = 1; i <= n; i++)
    {
        f(i, 0);
    }
    cout << ans << endl;
    return 0;
}