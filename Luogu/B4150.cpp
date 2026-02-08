#include <algorithm>
#include <iostream>
using namespace std;
int a, ans = 10;
int main()
{
    cin >> a;
    if (a > 3)
    {
        ans += min(a - 3, 5) * 3;
    }
    if (a > 8)
    {
        ans += (a - 8) * 5;
    }
    cout << ans << endl;
    return 0;
}