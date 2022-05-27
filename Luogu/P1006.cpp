#include <iostream>
using namespace std;
int mp[55][55], t[105][55][55];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    t[0][1][1] = mp[1][1];
    for (int step = 1; step <= m + n - 2; step++)
    {
        for (int a = max(1, step + 2 - m); a <= min(n, step + 1); a++)
        {
            for (int b = max(1, step + 2 - m); b <= min(n, step + 1); b++)
            {
                int ans1 = max(t[step - 1][a][b], t[step - 1][a - 1][b - 1]);
                int ans2 = max(t[step - 1][a - 1][b], t[step - 1][a][b - 1]);
                t[step][a][b] = max(ans1, ans2) + mp[a][step + 2 - a];
                if (a != b)
                {
                    t[step][a][b] += mp[b][step + 2 - b];
                }
            }
        }
    }
    cout << t[m + n - 2][n][n] << endl;
    return 0;
}