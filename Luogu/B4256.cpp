#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long p, x;
        cin >> p >> x;
        for (int res = 1, pw = 1; res <= p; res++)
        {
            pw = pw * x % p;
            if (pw == 1)
            {
                cout << res << endl;
                break;
            }
        }
    }
    return 0;
}