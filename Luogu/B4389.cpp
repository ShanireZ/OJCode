#include <algorithm>
#include <iostream>
using namespace std;
int n, ans;
string s, t;
int main()
{
    cin >> n >> s;
    t = s;
    reverse(t.begin(), t.end());
    for (int i = 0; i < (int)s.size() / 2; i++)
    {
        if (s[i] == t[i])
        {
            if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '5' || s[i] == '8')
            {
                continue;
            }
            else if (s[i] == '6' || s[i] == '9')
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
        }
        else
        {
            if ((s[i] == '6' && t[i] == '9') || (s[i] == '9' && t[i] == '6'))
            {
                continue;
            }
            else if ((s[i] == '3' || s[i] == '4' || s[i] == '7') && (t[i] == '3' || t[i] == '4' || t[i] == '7'))
            {
                ans += 2;
            }
            else
            {
                ans++;
            }
        }
    }
    if (s.size() % 2 == 1)
    {
        int mid = s.size() / 2;
        if (s[mid] != '0' && s[mid] != '1' && s[mid] != '2' && s[mid] != '5' && s[mid] != '8')
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}