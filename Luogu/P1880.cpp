#include <cstring>
#include <iostream>
using namespace std;
int dpmin[205][205], dpmax[205][205], w[205], qz[205];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[n + i] = w[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        qz[i] = qz[i - 1] + w[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        for (int j = i + 1; j <= n * 2; j++)
        {
            dpmin[i][j] = 0x3f3f3f3f, dpmax[i][j] = -1;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l <= n * 2; l++)
        {
            int r = l + len - 1;
            if (r >= n * 2)
            {
                continue;
            }
            for (int k = l; k < r; k++)
            {
                dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r] + (qz[r] - qz[l - 1]));
                dpmax[l][r] = max(dpmax[l][r], dpmax[l][k] + dpmax[k + 1][r] + (qz[r] - qz[l - 1]));
            }
        }
    }
    int ansmax = 0, ansmin = 0x3f3f3f3f;
    for (int l = 1; l <= n; l++)
    {
        int r = l + n - 1;
        ansmin = min(ansmin, dpmin[l][r]);
        ansmax = max(ansmax, dpmax[l][r]);
    }
    cout << ansmin << endl;
    cout << ansmax << endl;
    return 0;
}