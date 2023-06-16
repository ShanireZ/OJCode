#include <algorithm>
#include <iostream>
using namespace std;
int mp[35][35], ms[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
int main()
{
    int n, m, c1 = 0, c2 = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                mp[i][j] = 1, c1++;
            }
            else if (ch == '$')
            {
                mp[i][j] = 2, c2++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == 0)
            {
                continue;
            }
            int now = mp[i][j];
            for (int k = 0; k < 4; k++)
            {
                int ok = 1;
                for (int step = 1; step <= 4; step++)
                {
                    int nx = ms[k][0] * step + i, ny = ms[k][1] * step + j;
                    if (nx < 1 || nx > n || ny < 1 || ny > m || now != mp[nx][ny])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    cout << (now == 1 ? "Pleasing!" : "zylwins!") << "\n";
                    return 0;
                }
            }
        }
    }
    cout << (c1 == c2 ? "W" : "Z") << "\n";
    return 0;
}