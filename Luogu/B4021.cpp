#include <cmath>
#include <iostream>
using namespace std;
int cnt[100005];
int main()
{
    int n, t, a, ans = 0;
    cin >> n >> t;
    t = pow(10, t);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        a = a % t;
        cnt[a]++;
        if (cnt[a] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}