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
        if (s.size() % 2 == 0)
        {
            string a = s.substr(0, s.size() / 2);
            string b = s.substr(s.size() / 2, s.size() / 2);
            if (a == b)
            {
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}