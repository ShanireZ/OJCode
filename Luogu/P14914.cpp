#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int n, d, s[100005], t[100005], h[100005];
int main()
{
    cin >> n >> d >> s[1] >> t[1] >> h[1];
    for (int i = 2; i <= n + 1; i++)
    {
        cin >> s[i] >> t[i] >> h[i];
        if ((abs(h[i] - h[1]) > d) || (s[1] > s[i] && t[1] > t[i]) || (s[1] < s[i] && t[1] < t[i]))
        {
            cout << "No" << endl;
            continue;
        }
        if (s[i] == s[1] && t[i] == t[1])
        {
            cout << "Always" << endl;
            continue;
        }
        double x = 1.0 * (s[i] - s[1]) / (t[1] - s[1] - t[i] + s[i]);
        cout << fixed << setprecision(12) << s[1] + x * (t[1] - s[1]) << endl;
    }
    return 0;
}