#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int t[1000005];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, c, x, res = 0;
        cin >> n >> c;
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            t[x]++;
        }
        for (int i = 1; i <= 1000000; i++)
        {
            res += (t[i] > c ? c : t[i]);
        }
        cout << res << endl;
    }
    return 0;
}