#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        char ch = (i >= n / 2 + 1 - k / 2 && i <= n / 2 + 1 + k / 2) ? '#' : '.';
        for (int t = 1; t <= m - (n / 2 + 1); t++) // 左侧横杠部分
        {
            cout << ch;
        }
        int lmt = (i <= n / 2 + 1) ? i : n - i + 1;
        for (int t = 1; t <= lmt; t++)
        {
            cout << '#';
        }
        for (int t = 1; t <= n / 2 + 1 - lmt; t++)
        {
            cout << '.';
        }
        cout << endl;
    }
    return 0;
}