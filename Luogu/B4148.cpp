#include <algorithm>
#include <iostream>
using namespace std;
string to2[20] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110",
                  "0111", "1000", "1001", "1010", "1011", "1100", "1101",
                  "1110", "1111"};
int main()
{
    string s, str;
    cin >> s;
    s += ":";
    int p2 = s.find("::"), pos = s.find(":"), cnt = 0;
    while (pos != string::npos)
    {
        cnt++, pos = s.find(":", pos + 1);
    }
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (i == p2 + 1 && p2 != string::npos)
        {
            for (int j = 1; j <= 8 - cnt + 1; j++)
            {
                cout << "0000000000000000";
            }
            continue;
        }
        else if (s[i] != ':')
        {
            str += s[i];
            continue;
        }
        str.insert(str.begin(), 4 - (int)str.size(), '0');
        for (char c : str)
        {
            cout << (isdigit(c) ? to2[c - '0'] : to2[c - 'A' + 10]);
        }
        str.clear();
    }
    return 0;
}