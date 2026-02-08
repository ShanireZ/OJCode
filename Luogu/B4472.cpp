#include <algorithm>
#include <iostream>
using namespace std;
int n, p, now, a[100005], b[100005];
string s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            p = i;
            break;
        }
    }
    now = stoi(s.substr(p));
    for (int i = p - 1; i >= 0; i--)
    {
        now = (s[i] == 'a' ? a[now] : b[now]);
    }
    cout << now << endl;
    return 0;
}