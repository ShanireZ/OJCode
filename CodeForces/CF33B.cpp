#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int d[30][30], n;
string a, b, c;
int main()
{
    cin >> a >> b >> n;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        char x, y;
        int w;
        cin >> x >> y >> w;
        d[x - 'a' + 1][y - 'a' + 1] = min(d[x - 'a' + 1][y - 'a' + 1], w);
    }
    for (int i = 1; i <= 26; i++)
    {
        d[i][i] = 0;
    }
    for (int k = 1; k <= 26; k++)
    {
        for (int i = 1; i <= 26; i++)
        {
            for (int j = 1; j <= 26; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int tot = 0;
    if (a.size() != b.size())
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i] - 'a' + 1, y = b[i] - 'a' + 1;
        int p = 1;
        for (int j = 1; j <= 26; j++)
        {
            if (d[x][p] + d[y][p] > d[x][j] + d[y][j])
            {
                p = j;
            }
        }
        if (d[x][p] + d[y][p] >= 0x3f3f3f3f)
        {
            cout << -1 << endl;
            return 0;
        }
        c += 'a' + p - 1;
        tot += d[x][p] + d[y][p];
    }
    cout << tot << endl
         << c << endl;
    return 0;
}