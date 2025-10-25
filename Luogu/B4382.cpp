#include <algorithm>
#include <iostream>
using namespace std;
string t, s[10] = {"A320AN2", "A350AW2", "A380AW4", "B737BN2", "B747BW4", "B787BW2", "C919CN2"};
int main()
{
    char a, b, c;
    cin >> a >> b >> c;
    t = t + a + b + c;
    for (int i = 0; i < 7; i++)
    {
        if (s[i].find(t) != string::npos)
        {
            cout << s[i].substr(0, 4) << endl;
        }
    }
    return 0;
}