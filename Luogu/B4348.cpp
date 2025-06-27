#include <algorithm>
#include <iostream>
using namespace std;
int a, b, ans;
int main()
{
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        string s = to_string(i);
        sort(s.begin(), s.end());
        int ok = 1;
        for (int j = 0; j < (int)s.size(); j++)
        {
            if (j != s[j] - '0')
            {
                ok = 0;
                break;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}