#include <iostream>
#include <algorithm>
using namespace std;
int all[1005][1005];
int hang[1005];
int lie[1005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> all[i][j];
            hang[i] += all[i][j];
            lie[j] += all[i][j];
        }
    }
    int maxv = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (all[i][j] == 0)
            {
                int tot = hang[i] + lie[j];
                maxv = max(tot, maxv);
            }
        }
    }
    if (maxv == -1)
    {
        cout << "Bad Game!";
    }
    else
    {
        cout << maxv;
    }
    return 0;
}