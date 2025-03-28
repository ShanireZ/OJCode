#include <algorithm>
#include <iostream>
using namespace std;
string s, wd, all[205];
int main()
{
    while (getline(cin, s))
    {
        int pos = 0;
        for (char ch : s)
        {
            ch == ' ' ? all[++pos] = wd, wd = "" : wd += ch;
        }
        if (wd.size())
        {
            all[++pos] = wd, wd = "";
        }
        sort(all + 1, all + 1 + pos);
        cout << pos << " ";
        for (int i = 1; i <= pos; i++)
        {
            cout << all[i] << " ";
        }
        cout << endl;
    }
    return 0;
}