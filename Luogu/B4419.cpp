#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int ok = (s[0] != 0);
    for (int i = 1; i < (int)s.size(); i++)
    {
        if (s[i] != '0')
        {
            ok = 0;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}