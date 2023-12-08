#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if (s[i] == 'A')
        {
            cout << 'T';
        }
        else if (s[i] == 'T')
        {
            cout << 'A';
        }
        else if (s[i] == 'G')
        {
            cout << 'C';
        }
        else
        {
            cout << 'G';
        }
    }
    return 0;
}