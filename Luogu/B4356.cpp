#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int ans = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (i * j % 2 == 0)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}