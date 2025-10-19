#include <algorithm>
#include <iostream>
using namespace std;
int a, b, c, ans;
int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i <= 10 && i <= a / 2; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = c / 2; k <= c; k++)
            {
                if (i <= j && k <= j && (k == 0 || i * j <= k * k))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}