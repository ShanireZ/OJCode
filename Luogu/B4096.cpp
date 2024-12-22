#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, l, p, ans = 0;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        ans = max(ans, min(p, l - p));
    }
    cout << ans << endl;
    return 0;
}