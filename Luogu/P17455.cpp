#include <algorithm>
#include <iostream>
using namespace std;
int prim[1000005], rec[1000005], n, pos, ans;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (prim[i] == 0)
        {
            rec[++pos] = i;
            for (int j = i * 2; j <= n; j += i)
            {
                prim[j] = 1;
            }
        }
    }
    for (int i = 1; rec[i] <= n / 2 && i <= pos; i++)
    {
        if (prim[n - rec[i]] == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}