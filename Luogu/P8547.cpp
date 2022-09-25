#include <iostream>
using namespace std;
int t[40] = {0, 1234, 111, 123, 135, 147, 159, 210, 222, 234, 246,
             258, 321, 333, 345, 357, 420, 432, 444, 456, 531, 543,
             555, 630, 642, 654, 741, 753, 840, 852, 951, 1111}; // 31个
int main()
{
    int d;
    cin >> d;
    while (d--)
    {
        int x;
        cin >> x;
        long long ans = x / 720 * 31;
        x %= 720;
        int h = 12, m = 1, pos = 1;
        while (x)
        {
            int now = h * 100 + m;
            if (now == t[pos])
            {
                ans++, pos++;
            }
            x--, m++;
            if (m == 60)
            {
                m = 0, h = (h + 1) % 12;
            }
        }
        cout << ans << endl;
    }
    return 0;
}