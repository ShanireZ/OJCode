#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x1, x2;
        cin >> x1 >> s1 >> s2 >> s2 >> s2;
        if ((s1 == "kg" && s2 == "mg") || (s1 == "km" && s2 == "mm"))
        {
            x2 = x1 * 1000000;
        }
        else
        {
            x2 = x1 * 1000;
        }
        cout << x1 << " " << s1 << " = " << x2 << " " << s2 << endl;
    }
    return 0;
}