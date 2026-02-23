#include <algorithm>
#include <iostream>
using namespace std;
int n, pos, h[105][105], all[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> h[i][j];
            all[++pos] = h[i][j];
        }
    }
    sort(all + 1, all + pos + 1, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= pos; k++)
            {
                if (h[i][j] == all[k])
                {
                    cout << k << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}