#include <algorithm>
#include <iostream>
using namespace std;
int p, d, ans, t[2005];
int main()
{
    cin >> p >> d;
    while (d--)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            t[i]++;
            ans = max(ans, t[i]);
        }
        sort(t + 1, t + 1 + k);
    }
    cout << ans << endl;
    return 0;
}