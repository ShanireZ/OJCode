#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int T, rd, rec[105];
int main()
{
    cin >> T >> s;
    while (s.find("not") != string::npos)
    {
        rd++;
        int rpos = 0, pos = s.find("not");
        while (pos != (int)string::npos)
        {
            rec[++rpos] = pos;
            pos = s.find("not", pos + 1);
        }
        for (int i = rpos; i >= 1; i--)
        {
            s.erase(rec[i], 3);
        }
    }
    cout << s << endl;
    cout << rd << endl;
    return 0;
}