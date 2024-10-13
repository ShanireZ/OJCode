#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long w[500005], n, a, b;
int main()
{
    cin >> n >> a >> b;
    long long l = 1, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        r += w[i];
    }
    while (l <= r)
    {
        long long mid = (l + r) / 2, sum = 0;
        for (int i = n; i >= 1; i--)
        {
            if (w[i] > mid * a)
            {
                sum += (w[i] - mid * a) / b;
                if ((w[i] - mid * a) % b != 0)
                {
                    sum++;
                }
            }
        }
        sum <= mid ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}