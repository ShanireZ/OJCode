#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    int n, k, pos = 0;
    cin >> n >> k >> s;
    for (int i = n - 1; i >= 1; i--)
    {
        int now = s.find(s[i]);
        if (now == (int)string::npos || now == i)
        {
            pos = i;
            break;
        }
    }
    if (n - pos < k)
    {
        cout << "-1\n";
    }
    else
    {
        cout << n - pos << "\n";
        cout << s.substr(0, pos + 1) << "\n";
        for (int i = pos + 1; i < n; i++)
        {
            cout << s[i] << "\n";
        }
    }
    return 0;
}