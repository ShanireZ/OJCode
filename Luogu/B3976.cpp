#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (char c : s)
    {
        if (isalpha(c))
        {
            cout << c;
        }
    }
    return 0;
}