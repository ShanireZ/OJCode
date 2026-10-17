#include <algorithm>
#include <iostream>
using namespace std;
int n, m, x, ans, rd[105], s[505], js[105][105];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> m;
        s[x] = i;
        for (int j = 1; j <= m; j++)
        {
            cin >> js[i][j]; //? 第i個攝像頭監視的第j個位置
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; js[i][j] != 0; j++)
        {
            x = js[i][j];
            rd[s[x]] += (s[x] != 0);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += (rd[i] == 0);
    }
    if (ans == n)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << n - ans << endl;
    return 0;
}