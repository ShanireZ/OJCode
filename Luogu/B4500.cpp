#include <algorithm>
#include <iostream>
using namespace std;
string a, b, c;
int main()
{
    cin >> a >> b >> c;
    int x = b[0] - a[0];
    for (char ch : c)
    {
        ch -= x;
        if (ch > 'Z')
        {
            ch -= 26;
        }
        else if (ch < 'A')
        {
            ch += 26;
        }
        cout << ch;
    }
    return 0;
}