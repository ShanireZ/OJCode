#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    int p = 1, res = 0;
    for (char c : s)
    {
        if ((c == 'i' && p == 0) || (c == 'o' && p == 1))
        {
            res++, p++;
        }
        p = (p + 1) % 2;
    }
    cout << res + (p == 0) << endl;
    return 0;
}