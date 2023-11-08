#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                ans += __gcd(i, j);
            }
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}