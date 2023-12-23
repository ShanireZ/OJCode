#include <algorithm>
#include <iostream>
using namespace std;
long long w[5005];
int main()
{
    long long n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        w[i] -= x;
    }
    long long tot = 0;
    for (int i = 1; i < k; i++)
    {
        tot += w[i];
    }
    for (int i = k; i <= n; i++)
    {
        tot = tot + w[i] - w[i - k];
        if (tot >= m)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}