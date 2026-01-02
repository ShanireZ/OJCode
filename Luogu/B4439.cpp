#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, p;
        cin >> x >> p;
        if (x >= 500 && p < 500)
        {
            ans += p, cnt++;
        }
    }
    cout << cnt << " " << ans << endl;
    return 0;
}