#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    long long ans = n + n - 1;
    if (c >= n)
    {
        ans += min(b - a + 1, 2 * (c - n + 1));
    }
    cout << ans << endl;
    return 0;
}