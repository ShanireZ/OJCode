#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int k = 0; k < (int)s.size(); k++)
    {
        cout << "+(+![]";
        int num = s[k] - '0';
        for (int i = 1; i <= num; i++)
        {
            cout << "+!![]";
        }
        cout << ")+[]";
    }
    return 0;
}
// TAG: js