#include <algorithm>
#include <iostream>
using namespace std;
#define MX 2005
struct Cow
{
    int p, c, x;
    bool operator<(const Cow oth) const
    {
        return x < oth.x;
    }
};
Cow cs[MX];
int dx[MX][MX], dc[MX][MX], ans, n, a, b;
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> cs[i].p >> cs[i].c >> cs[i].x;
    }
    sort(cs + 1, cs + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= b; j++)
        {
            dx[i][j] = dx[i - 1][j];
            if (j >= cs[i].c * cs[i].x)
            {
                dx[i][j] = max(dx[i][j], dx[i - 1][j - cs[i].c * cs[i].x] + cs[i].p);
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= a; j++)
        {
            dc[i][j] = dc[i + 1][j];
            if (j >= cs[i].c)
            {
                dc[i][j] = max(dc[i][j], dc[i + 1][j - cs[i].c] + cs[i].p);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= cs[i].c; j++)
        {
            int x = j * cs[i].x, c = cs[i].c - j;
            if (x <= b && c <= a)
            {
                ans = max(ans, dx[i - 1][b - x] + dc[i + 1][a - c] + cs[i].p);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}