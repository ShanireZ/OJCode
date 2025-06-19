#include <algorithm>
#include <iostream>
using namespace std;
int solve(int d)
{
    if (d <= 10)
    {
        return d * 20;
    }
    else if (d <= 50)
    {
        return 200 + (d - 10 + 4) / 5 * 80;
    }
    else
    {
        return 200 + 640 + (d - 50 + 9) / 10 * 120;
    }
}
int main()
{
    int n, ans = 1e9;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int res = solve(i) + solve(n - i);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}