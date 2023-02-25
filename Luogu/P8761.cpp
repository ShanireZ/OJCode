#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 'a' - 'A';
        }
        cout << s[i];
    }
    return 0;
}