#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s[1005], x;
int main()
{
    int pos = 0;
    while (cin >> x)
    {
        s[++pos] = x;
    }
    for (int i = pos; i >= 1; i--)
    {
        if (isdigit(s[i][0]))
        {
            reverse(s[i].begin(), s[i].end());
        }
        else if (islower(s[i][0]))
        {
            transform(s[i].begin(), s[i].end(), s[i].begin(), ::toupper);
        }
        else
        {
            transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
        }
        cout << s[i] << " ";
    }
    return 0;
}