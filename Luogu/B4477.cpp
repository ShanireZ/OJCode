#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, ans;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n && m > 0; i++)
    {
        long long r, c;
        cin >> r >> c;
        r = r * c;
        m -= r, ans += 2;
    }
    cout << ans << endl;
    return 0;
}