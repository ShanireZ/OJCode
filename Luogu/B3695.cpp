#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
bitset<30005> s[30005];
bitset<30005> base;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        base[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int c, x;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            cin >> x;
            s[i][x] = 1;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            s[x] = (s[x] << y) & base;
        }
        else if (opt == 2)
        {
            s[x] = (s[x] >> y) & base;
        }
        else if (opt == 3)
        {
            cout << (s[x] & s[y]).count() << "\n";
        }
        else if (opt == 4)
        {
            cout << (s[x] | s[y]).count() << "\n";
        }
        else if (opt == 5)
        {
            cout << (s[x] ^ s[y]).count() << "\n";
        }
    }
    return 0;
}