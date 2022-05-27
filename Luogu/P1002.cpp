#include <iostream>
using namespace std;
long long mp[25][25];
int h[10][2] = {{0, 0}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int main()
{
    int fx, fy, hx, hy;
    cin >> fx >> fy >> hx >> hy;
    fx++, fy++, hx++, hy++;
    for (int i = 0; i <= 8; i++)
    {
        int x = hx + h[i][0], y = hy + h[i][1];
        mp[x][y] = -1;
    }
    mp[1][1] = 1;
    for (int i = 1; i <= fx; i++)
    {
        for (int j = 1; j <= fy; j++)
        {
            if (mp[i][j] < 0)
            {
                continue;
            }
            if (mp[i - 1][j] > 0)
            {
                mp[i][j] += mp[i - 1][j];
            }
            if (mp[i][j - 1] > 0)
            {
                mp[i][j] += mp[i][j - 1];
            }
        }
    }
    cout << mp[fx][fy] << endl;
    return 0;
}