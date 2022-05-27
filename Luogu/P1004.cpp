#include <algorithm>
#include <iostream>
using namespace std;
int m[15][15], t[25][15][15];
int main()
{
    int n;
    cin >> n;
    int x, y, c;
    cin >> x >> y >> c;
    while (x != 0 || y != 0 || c != 0)
    {
        m[x][y] = c;
        cin >> x >> y >> c;
    }
    t[0][1][1] = m[1][1];
    for (int step = 1; step <= n + n - 2; step++)
    {
        for (int a = max(1, step + 2 - n); a <= min(step + 1, n); a++)
        {
            for (int b = max(1, step + 2 - n); b <= min(step + 1, n); b++)
            {
                int ans1 = max(t[step - 1][a][b], t[step - 1][a - 1][b - 1]);
                int ans2 = max(t[step - 1][a - 1][b], t[step - 1][a][b - 1]);
                t[step][a][b] = max(ans1, ans2) + m[a][step + 2 - a];
                if (a != b)
                {
                    t[step][a][b] += m[b][step + 2 - b];
                }
            }
        }
    }
    cout << t[n + n - 2][n][n] << endl;
    return 0;
}