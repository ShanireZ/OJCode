#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string s;
unordered_map<string, bool> m;
int main()
{
    cin >> s;
    while (s != "0")
    {
        if (m[s] == false)
        {
            cout << s;
            m[s] = 1;
        }
        cin >> s;
    }
    return 0;
}