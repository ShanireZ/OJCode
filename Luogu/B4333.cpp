#include <algorithm>
#include <iostream>
using namespace std;
string s;
int now = 1, ans = 1;
int main()
{
    cin >> s;
    for (int i = 1; i < (int)s.size(); i++)
    {
        s[i] == s[i - 1] ? now++ : now = 1;
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}