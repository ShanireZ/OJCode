#include <algorithm>
#include <iostream>
using namespace std;
int n, ms[100005];
string s;
int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> ms[i];
        if (i % 2 == 1)
        {
            ms[i] = 26 - ms[i] % 26;
        }
        ms[i] = ms[i] % 26;
    }
    for (int i = n; i >= 1; i--)
    {
        ms[i] = (ms[i] + ms[i + 1]) % 26;
        s[i - 1] = (s[i - 1] - 'a' + ms[i]) % 26 + 'a';
    }
    cout << s << endl;
    return 0;
}