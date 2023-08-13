#include <algorithm>
#include <iostream>
using namespace std;
long long tot[10005], a[1000005];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
        tot[i % k] += a[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (i % 2 == 1)
        {
            a[i] = tot[i % k] % i;
        }
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}