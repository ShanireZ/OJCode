#include <algorithm>
#include <iostream>
using namespace std;
int v[1005][15], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ok = 1;
        for (int j = 1; j <= n; j++)
        {
            ok = 1;
            for (int k = 1; k <= m; k++)
            {
                if (v[i][k] >= v[j][k])
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                cout << j << endl;
                break;
            }
        }
        if (ok == 0)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}