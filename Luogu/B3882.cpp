#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, rs;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        rs = s = to_string(i);
        reverse(rs.begin(), rs.end());
        if (s == rs)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}