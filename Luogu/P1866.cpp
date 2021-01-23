#include <iostream>
#include <algorithm>
using namespace std;
int maxn[55];
int main()
{
    int n, mod = 1000000007;
    long long tot = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> maxn[i];
    }
    sort(maxn, maxn + n);
    for (int i = 0; i < n; i++)
    {
        tot = tot * (maxn[i] - i) % mod;
    }
    cout << tot;
    return 0;
}