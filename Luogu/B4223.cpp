#include <algorithm>
#include <iostream>
using namespace std;
long long n, w, x[5], y[5];
int main()
{
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long res = w;
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == x[j] || y[i] == y[j])
            {
                continue;
            }
            if (x[i] < y[j])
            {
                res = min(res, y[j] - 1);
            }
            else if (y[i] < x[j])
            {
                res = min(res, x[j] - 1);
            }
        }
        cout << res << endl;
    }
    return 0;
}