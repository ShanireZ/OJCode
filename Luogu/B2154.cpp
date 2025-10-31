#include <iostream>
using namespace std;
int main()
{
    int ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            ans += (x % 10 == 1);
            x /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}