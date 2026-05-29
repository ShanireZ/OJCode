#include <algorithm>
#include <iostream>
using namespace std;
int T, n, c[15];
string s;
int main()
{
    cin >> T;
    while (T--)
    {
        fill(c, c + 10, 0);
        cin >> n >> s;
        for (char ch : s)
        {
            c[ch - '0']++;
        }
        int l = 0, r = n / 4;
        while (l <= r)
        {
            int mid = (l + r) / 2; // 将时辰分为两类分别0/1开头
            int mn = max(0, mid - c[0]);
            int mx = min({mid, c[1], c[0] + c[1] - mid, c[0] + c[1] + c[2] + c[3] + c[4] + c[5] - mid * 2});
            mn <= mx ? l = mid + 1 : r = mid - 1;
        }
        cout << r << endl;
    }
    return 0;
}