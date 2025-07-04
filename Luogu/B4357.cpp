#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int ans = 0, l, r;
    cin >> l >> r;
    for (int i = 0; i <= 13; i++)
    {
        for (int j = i; j <= 13; j++)
        {
            int x = (1 << i) + (1 << j);
            ans += (x >= l && x <= r);
        }
    }
    cout << ans << endl;
    return 0;
}