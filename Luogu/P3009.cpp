#include <iostream>
using namespace std;
int main()
{
    int n, now;
    cin >> n >> now;
    int ans = now, tot = now;
    for (int i = 2; i <= n; i++)
    {
        cin >> now;
        tot = max(tot + now, now);
        ans = max(ans, tot);
    }
    cout << ans << endl;
    return 0;
}