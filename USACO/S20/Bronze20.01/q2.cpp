#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;
int cows[1005];
int usd[1005];
int main()
{
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> cows[i];
    }
    for (int i = 1; i <= n; i++)
    {
        memset(usd, 0, sizeof(usd));
        usd[i] = 1;
        int pre = i, trig = 1;
        for (int j = 2; j <= n; j++)
        {
            int cur = cows[j - 1] - pre;
            if (usd[cur] == 1 || cur < 1 || cur > n)
            {
                trig = 0;
                break;
            }
            usd[cur] = 1;
            pre = cur;
        }
        if (trig)
        {
            cout << i;
            pre = i;
            for (int j = 2; j <= n; j++)
            {
                cout << " " << cows[j - 1] - pre;
                pre = cows[j - 1] - pre;
            }
            return 0;
        }
    }
    return 0;
}