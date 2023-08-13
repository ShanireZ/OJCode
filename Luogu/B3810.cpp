#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, ans, now, mid;
int main()
{
    cin >> s;
    ans = s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        for (int j = i; j < (int)s.size(); j++)
        {
            mid = s.substr(i, j - i + 1);
            reverse(mid.begin(), mid.end());
            now = s.substr(0, i) + mid + s.substr(j + 1);
            ans = min(ans, now);
        }
    }
    cout << ans << "\n";
    return 0;
}