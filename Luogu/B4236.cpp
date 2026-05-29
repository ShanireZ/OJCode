#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, ans = 0, base = 5;
    cin >> n;
    while (n / base != 0)
    {
        ans += n / base;
        base *= 5;
    }
    cout << ans << endl;
    return 0;
}