#include <algorithm>
#include <iostream>
using namespace std;
int cnt[1005], yf[1005];
int main()
{
    int n, m, rid = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> yf[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] * yf[i] > cnt[rid] * yf[rid])
        {
            rid = i;
        }
    }
    cout << rid << endl;
    return 0;
}