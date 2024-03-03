#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sz = s.size();
    for (int i = 0; i <= sz - 1; i++)
    {
        if (s[i] != s[sz - (i + 1)])
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}