#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    sort(s.begin(), s.end(), greater<char>());
    for (char c : s)
    {
        if (isdigit(c))
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}