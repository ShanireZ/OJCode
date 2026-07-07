#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, k, m, ans = 0;
    cin >> n >> k >> m;
    while (n < m)
    {
        n += n * k, ans++;
    }
    cout << ans << endl;
    return 0;
}