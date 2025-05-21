#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long k, ans = 0;
    char c;
    cin >> k >> c;
    for (int i = 255; i - k >= 0; i--)
    {
        ans += (i - k + 1) * (i - k + 1);
    }
    cout << ans << endl;
    return 0;
}