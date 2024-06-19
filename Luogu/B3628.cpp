#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, x, ans = 1, now = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        now += x;
        if (now <= 0)
        {
            ans = max(-now + 2, ans);
        }
    }
    cout << ans << endl;
    return 0;
}