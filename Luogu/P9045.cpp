#include <algorithm>
#include <iostream>
using namespace std;
int vis[500005];
int main()
{
    int n, k, cnt = 0;
    cin >> n >> k;
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (vis[x] && i <= k)
        {
            tot -= i, cnt++;
        }
        else if (vis[x] == 0)
        {
            vis[x] = 1;
            if (i > k && cnt != 0)
            {
                tot += i, cnt--;
            }
        }
    }
    if (cnt)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << tot << endl;
    }
    return 0;
}