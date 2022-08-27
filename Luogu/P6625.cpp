#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    long long tot = x, ans = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        tot += x;
        if (tot > 0)
        {
            ans += tot;
        }
    }
    cout << ans << endl;
    return 0;
}