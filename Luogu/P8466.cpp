#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt = 1;
        for (int i = 1; i < s.size(); i++)
        {
            cnt = (s[i] != s[i - 1]) ? 1 : cnt + 1;
            if (cnt == 4)
            {
                break;
            }
        }
        if (cnt == 4 || (s[0] == 'D' && s[1] == 'X'))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}