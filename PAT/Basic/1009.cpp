#include <iostream>
#include <string>
using namespace std;
string s[105];
int main()
{
    int pos = 0;
    cin >> s[++pos];
    while ((int)s[pos].size())
    {
        cin >> s[++pos];
    }
    for (int i = pos - 1; i > 0; i--)
    {
        cout << s[i];
        if (i != 1)
        {
            cout << " ";
        }
    }
    return 0;
}