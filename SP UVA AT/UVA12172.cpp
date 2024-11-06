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
            cout << ans[n] << ' ';
        }
        else
        {
            cout << pre[n % 7];
            int cmn = n / 7 + (n % 7 != 0) - 3;
            for (int i = 1; i <= cmn; i++)
            {
                cout << 8;
            }
            cout << ' ';
        }
        cout << (n % 2 == 1 ? 7 : 1);
        int cmx = n / 2 - 1;
        for (int i = 1; i <= cmx; i++)
        {
            cout << 1;
        }
        cout << endl;
    }
    return 0;
}