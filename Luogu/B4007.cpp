#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            ans += (x % 10 == k);
            x /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}