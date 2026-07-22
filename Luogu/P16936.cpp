#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
string s;
int main()
{
    cin >> n >> s;
    sort(s.begin(), s.end());
    for (int i = 1; i <= n; i += 2)
    {
        ans += s[i] - s[i - 1];
    }
    cout << ans << endl;
    return 0;
}