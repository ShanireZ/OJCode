#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    getline(cin, s); //! 整行读入
    for (int i = 0; i <= s.size() - 1; i++)
    {
        char x;
        if ((s[i] >= 'b' && s[i] <= 'z') ||
            (s[i] >= 'B' && s[i] <= 'Z'))
        {
            x = s[i] - 1;
            cout << x;
        }
        else if (s[i] == 'A' || s[i] == 'a')
        {
            x = s[i] + 25;
            cout << x;
        }
        else
        {
            cout << s[i];
        }
    }
    return 0;
}