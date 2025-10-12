#include <algorithm>
#include <iostream>
using namespace std;
int n, prim[100005];
int main()
{
    for (int i = 2; i <= 100000; i++)
    {
        if (prim[i] == 0)
        {
            for (int j = 2; i * j <= 100000; j++)
            {
                prim[i * j] = 1;
            }
        }
    }
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += (prim[i] == 0);
    }
    cout << ans << endl;
    return 0;
}