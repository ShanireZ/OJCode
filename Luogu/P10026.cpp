#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long k, n, cnt = 0, trig = 0, status = 0;
        cin >> k >> n;
        if (n == 0)
        {
            cout << (k != 0 ? "Yes" : "No") << endl;
        }
        else if (n == 1)
        {
            cout << (k != 1 && k != 3 ? "Yes" : "No") << endl;
        }
        else
        {
            while (n > 1)
            {
                cnt++;
                (n % 2 == 0) ? (n /= 2) : (n += 1, trig = cnt);
            }
            // 差1次时,n不能为2的次方或2的次方减1
            cout << (k - cnt < 0 || (k - cnt == 1 && trig <= 1) ? "No" : "Yes") << endl;
        }
    }
    return 0;
}