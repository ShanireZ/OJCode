#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    long long n, a, k, b;
    cin >> n >> a >> k >> b;
    if (n % 2 == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    n /= 2;
    long long ans = n * a;
    ans = min(ans, (n / k + (n % k != 0)) * b);
    ans = min(ans, (n / k) * b + (n % k) * a);
    cout << ans * 2 << endl;
    return 0;
}