#include <cstring>
#include <iostream>
using namespace std;
int dpmin[305][305], w[305], qz[305];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        qz[i] = qz[i - 1] + w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            dpmin[i][j] = 0x3f3f3f3f;
        }
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l <= n; l++)
        {
            int r = l + len - 1;
            if (r > n)
            {
                continue;
            }
            for (int k = l; k < r; k++)
            {
                dpmin[l][r] = min(dpmin[l][r], dpmin[l][k] + dpmin[k + 1][r] + (qz[r] - qz[l - 1]));
            }
        }
    }
    cout << dpmin[1][n] << endl;
    return 0;
}