#include <algorithm>
#include <iostream>
using namespace std;
int ans[20] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};
int pre[10] = {888, 108, 188, 200, 208, 288, 688}, n, T;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        if (n <= 14)
        {
            cout << ans[n] << endl;
            continue;
        }
        int c8 = (n + 6) / 7 - 3, ex = n % 7;
        cout << pre[ex];
        for (int i = 1; i <= c8; i++)
        {
            cout << 8;
        }
        cout << endl;
    }
    return 0;
}