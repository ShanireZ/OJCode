#include <iostream>
#include <algorithm>
using namespace std;
int all[105];
int main()
{
    int n, m, maxA = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int tmp;
            cin >> tmp;
            all[i] = max(all[i], tmp);
        }
        maxA = max(maxA, all[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << all[i];
        if (i < n)
        {
            cout << " ";
        }
        else
        {
            cout << endl
                 << maxA;
        }
    }
    return 0;
}