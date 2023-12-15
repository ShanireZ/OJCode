#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        ans ^= x;
    }
    cout << ans << " " << 0 << endl;
    return 0;
}