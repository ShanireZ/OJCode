#include <cstring>
#include <iostream>
using namespace std;
int dp[10005], xdp[10005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        memset(xdp, 0, sizeof(xdp));
        xdp[0] = 1;
        int x;
        cin >> x;
        while (x != -1)
        {
            for (int j = 10000; j >= x; j--)
            {
                xdp[j] = max(xdp[j], xdp[j - x]);
            }
            cin >> x;
        }
        for (int i = 0; i <= 10000; i++)
        {
            dp[i] += xdp[i];
        }
    }
    for (int i = 10000; i >= 0; i--)
    {
        if (dp[i] == n)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}