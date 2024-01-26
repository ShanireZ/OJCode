#include <algorithm>
#include <iostream>
using namespace std;
char chs[105][105];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> chs[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int tt = 1; tt <= k; tt++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int t = 1; t <= k; t++)
                {
                    cout << chs[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}