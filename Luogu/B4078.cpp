#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, s[105][25];
double avg[25];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            avg[j] += s[i][j];
        }
    }
    for (int j = 1; j <= m; j++)
    {
        avg[j] = 1.0 * avg[j] / n;
    }
    for (int i = 1; i <= n; i++)
    {
        ans = 0;
        for (int j = 1; j <= m; j++)
        {
            ans += (s[i][j] >= avg[j]);
        }
        cout << ans << endl;
    }
    return 0;
}