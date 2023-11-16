#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int k, l, r, ans = 0;
    cin >> k >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 10 == k || i % k == 0)
        {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}