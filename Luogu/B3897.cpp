#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int k, a, b, c, ans = 0;
    cin >> k >> a >> b >> c;
    while (k--)
    {
        int x;
        cin >> x;
        if (x <= 10)
        {
            ans += x * a;
        }
        else if (x <= 100)
        {
            ans += 10 * a + (x - 10) * b;
        }
        else
        {
            ans += 10 * a + 90 * b + (x - 100) * c;
        }
    }
    cout << ans << endl;
    return 0;
}