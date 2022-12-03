#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double lmn[5005];
long long x[5005], y[5005], g[5005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        lmn[i] = 3e6;
    }
    g[1] = 1;
    int last = 1;
    double tot = 0;
    for (int t = 1; t < n; t++)
    {
        int now = 0;
        double len = 3e6;
        for (int i = 1; i <= n; i++)
        {
            lmn[i] = min(lmn[i], sqrt((x[i] - x[last]) * (x[i] - x[last]) + (y[i] - y[last]) * (y[i] - y[last])));
            if (g[i] == 0 && lmn[i] < len)
            {
                len = lmn[i], now = i;
            }
        }
        last = now, tot += len, g[now] = 1;
    }
    cout << fixed << setprecision(2) << tot << endl;
    return 0;
}