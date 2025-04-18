#include <algorithm>
#include <iostream>
using namespace std;
bool prim[20000005];
char res[20000005];
int m, n, ans;
int main()
{
    cin >> m >> n;
    fill(res + m, res + n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        if (!prim[i])
        {
            res[i] = -1;
            for (int j = i + i; j <= n; j += i)
            {
                prim[j] = 1;
                (j / i % i == 0) ? res[j] = 0 : res[j] *= -1;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        ans += res[i];
    }
    cout << ans << endl;
    return 0;
}