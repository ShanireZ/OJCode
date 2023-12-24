#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long n, ans = 0;
        cin >> n >> s;
        for (int i = 0; i < n / 2 + n % 2; i++) // n为奇数时还需要验证中心位置是否合法
        {
            char c = s[i], rc = s[n - 1 - i];
            if ((c != 'A' && c != 'T' && c != 'C' && c != 'G') ||
                (rc != 'A' && rc != 'T' && rc != 'C' && rc != 'G'))
            {
                ans = 0;
                break;
            }
            if ((c == 'A' && rc == 'T') ||
                (c == 'T' && rc == 'A') ||
                (c == 'G' && rc == 'C') ||
                (c == 'C' && rc == 'G'))
            {
                ans += n + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}