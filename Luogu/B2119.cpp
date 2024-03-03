#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int sz = s.size();
    if (s[sz - 1] == 'r' && s[sz - 2] == 'e')
    {
        s.pop_back();
        s.pop_back();
    }
    else if (s[sz - 1] == 'y' && s[sz - 2] == 'l')
    {
        s.pop_back();
        s.pop_back();
    }
    else if (s[sz - 1] == 'g' && s[sz - 2] == 'n' && s[sz - 3] == 'i')
    {
        s.pop_back();
        s.pop_back();
        s.pop_back();
    }
    cout << s << endl;
    return 0;
}