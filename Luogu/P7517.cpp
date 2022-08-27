#include <iostream>
using namespace std;
int t[500005], a[200005];
int main()
{
    int n, maxa = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        t[a[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; a[i] * j <= maxa; j++)
        {
            ans += t[a[i] * j];
            if (j == 1 && t[a[i]])
            {
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}