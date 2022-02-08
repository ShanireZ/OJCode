#include <iostream>
using namespace std;
int cost[100005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    int l = 1, r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int team = 1, tot = 0, trig = 1;
        for (int i = 1; i <= n; i++)
        {
            if (cost[i] > mid)
            {
                trig = 0;
                break;
            }
            if (tot + cost[i] > mid)
            {
                tot = cost[i];
                team++;
            }
            else
            {
                tot += cost[i];
            }
        }
        if (trig == 0 || team > m)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << endl;
    return 0;
}