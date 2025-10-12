#include <algorithm>
#include <iostream>
using namespace std;
int n, ans, ok[100005];
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (ok[i] == 0)
        {
            for (int j = 2; i * j <= n; j++)
            {
                ok[i * j] = 1;
            }
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}