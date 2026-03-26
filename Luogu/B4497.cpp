#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int l, r, ans = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int x = i, c = 0;
        while (x)
        {
            c += (x % 10 == 2);
            x /= 10;
        }
        ans += (c == 3);
    }
    cout << ans << endl;
    return 0;
}