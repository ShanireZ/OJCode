#include <iostream>
#include <algorithm>
using namespace std;
int h[1000005], n, m;
bool check(int lmt)
{
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += max(h[i] - lmt, 0);
    }
    if (tot >= m)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    int L = 0, R = 1000000000;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (check(mid))
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    cout << R;
    return 0;
}