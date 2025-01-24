#include <algorithm>
#include <iostream>
using namespace std;
int t[105], l[105];
int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> l[i];
    }
    for (int i = 1; i <= d; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, t[j] * (i + l[j]));
        }
        cout << ans << endl;
    }
    return 0;
}