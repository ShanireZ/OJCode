#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int t, now = i;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            int pre = now, res = 0;
            while (now)
            {
                res += now % 10;
                now /= 10;
            }
            now = res;
            if (pre == now)
            {
                break;
            }
        }
        cout << now << " ";
    }
    return 0;
}