#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k, r = 0, ans = 0;
    cin >> n >> k;
    while (n)
    {
        ans += n, r += n; // 有可能之前剩餘的菸頭也能換煙
        n = r / k, r = r % k;
    }
    cout << ans << endl;
    return 0;
}