#include <iostream>
#include <string>
using namespace std;
int ans, n;
string m[105];
void check(int x, int y)
{
    int au = x - 1, ad = x + 1, bl = y - 1, br = y + 1;
    while (au > 0 && ad <= n && bl > 0 && br <= n && m[au][bl] == '1' && m[au][br] == '1' && m[ad][bl] == '1' && m[ad][br] == '1')
    {
        ans++, au--, ad++, bl--, br++;
    }
    if (m[x][y + 1] == '1' && m[x + 1][y] == '1' && m[x + 1][y + 1] == '1')
    {
        ans++;
        au = x - 1, ad = x + 2, bl = y - 1, br = y + 2;
        while (au > 0 && ad <= n && bl > 0 && br <= n && m[au][bl] == '1' && m[au][br] == '1' && m[ad][bl] == '1' && m[ad][br] == '1')
        {
            ans++, au--, ad++, bl--, br++;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i];
        m[i].insert(0, "0");
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (m[i][j] == '1')
            {
                check(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}