#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int ex = k - min(n, m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == j && k)
                {
                    k--;
                    cout << 'S';
                }
                else if (ex > 0)
                {
                    ex--;
                    cout << 'S';
                }
                else
                {
                    cout << '.';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}