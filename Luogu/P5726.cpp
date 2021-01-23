#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tot = 0, maxs = -1, mins = 20;
    for (int i = 1; i <= n; i++)
    {
        int score;
        cin >> score;
        tot += score;
        maxs = max(maxs, score);
        mins = min(mins, score);
    }
    tot = tot - maxs - mins;
    n = n - 2;
    cout << fixed << setprecision(2) << 1.0 * tot / n;
    return 0;
}