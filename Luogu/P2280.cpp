#include <iostream>
using namespace std;
int s[5005][5005];
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        s[x + 1][y + 1] = v;
    }
    for (int i = 1; i <= 5001; i++)
    {
        for (int j = 1; j <= 5001; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = 1; i + m - 1 <= 5001; i++)
    {
        for (int j = 1; j + m - 1 <= 5001; j++)
        {
            int x = i + m - 1, y = j + m - 1;
            ans = max(s[x][y] + s[i - 1][j - 1] - s[i - 1][y] - s[x][j - 1], ans);
        }
    }
    cout << ans << endl;
    return 0;
}