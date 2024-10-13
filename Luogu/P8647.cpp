#include <algorithm>
#include <iostream>
using namespace std;
int h[100005], w[100005], n, k;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> w[i];
    }
    int l = 1, r = 100000;
    while (l <= r)
    {
        long long mid = (l + r) / 2, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += (h[i] / mid) * (w[i] / mid);
        }
        sum >= k ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}