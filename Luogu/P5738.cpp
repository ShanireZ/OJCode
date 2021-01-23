#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    double maxavg = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxs = -1, mins = 0x3f3f3f3f, tot = 0;
        for (int j = 1; j <= m; j++)
        {
            int s;
            cin >> s;
            tot += s;
            maxs = max(maxs, s);
            mins = min(mins, s);
        }
        double avg = 1.0 * (tot - maxs - mins) / (m - 2);
        maxavg = max(maxavg, avg);
    }
    cout << fixed << setprecision(2) << maxavg;
    return 0;
}