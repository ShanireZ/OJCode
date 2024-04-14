#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k, ans = 0;
    cin >> n >> k;
    while (n)
    {
        ans += n;
        n = n / k;
    }
    cout << ans << endl;
    return 0;
}