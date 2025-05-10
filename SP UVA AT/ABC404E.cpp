#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int n, ans, c[2005], a[2005], qa[2005];
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> c[i];
        c[i] = max(i - c[i], 0);
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        qa[i] = a[i] + qa[i - 1];
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] == 0)
        {
            continue;
        }
        int cnt = qa[i - 1] - qa[c[i] - 1];
        if (cnt == 0)
        {
            int p = c[i];
            for (int j = c[i]; j < i; j++)
            {
                if (c[j] < c[p])
                {
                    p = j;
                }
            }
            a[p]++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}