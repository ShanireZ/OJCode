#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long cnt = r - l + 1;
        long long ans = (l % 2 == 1 && cnt % 2 == 1) + cnt / 2;
        cout << ans << endl;
    }
    return 0;
}