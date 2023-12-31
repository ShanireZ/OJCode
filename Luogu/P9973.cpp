#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, ss = "You are right, but ";
int main()
{
    getline(cin, s);
    if (s.substr(0, 19) == ss)
    {
        cout << "AI" << endl;
    }
    else
    {
        cout << "Human" << endl;
    }
    return 0;
}
// TAG: 字符串应用