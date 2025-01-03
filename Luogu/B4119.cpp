#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int n;
    cin >> n >> s;
    if (n == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    for (int len = 1; len <= n / 2; len++)
    {
        if (n % len != 0)
        {
            continue;
        }
        string rp = s.substr(0, len);
        int ok = 1;
        for (int i = 1; i < n / len; i++)
        {
            if (rp != s.substr(i * len, len))
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}