#include <algorithm>
#include <iostream>
using namespace std;
int T, n, r[100005], v[100005];
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> r[i];
            v[i] = r[i];
        }
        sort(v + 1, v + n + 1);
        cout << "Case #" << t << ":";
        for (int i = 1; i <= n; i++)
        {
            int p = upper_bound(v + 1, v + 1 + n, r[i] * 2) - v - 1;
            if (v[p] == r[i])
            {
                p--;
            }
            cout << " " << (p ? v[p] : -1);
        }
        cout << endl;
    }
    return 0;
}