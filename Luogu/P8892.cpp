#include <iostream>
#include <string>
using namespace std;
string a, b, c;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a.size() < b.size())
        {
            cout << "N\n";
            continue;
        }
        int pos = a.find(b[0]), tag = 0;
        while (tag == 0 && pos != string::npos)
        {
            c = a.substr(pos) + a.substr(0, pos);
            int fpos = 0, ok = 1;
            for (int i = 1; i < b.size(); i++)
            {
                fpos = c.find(b[i], fpos + 1);
                if (fpos == string::npos)
                {
                    ok = 0;
                    break;
                }
            }
            tag = ok, pos = a.find(b[0], pos + 1);
        }
        if (tag)
        {
            cout << "Y\n";
        }
        else
        {
            cout << "N\n";
        }
    }
    return 0;
}