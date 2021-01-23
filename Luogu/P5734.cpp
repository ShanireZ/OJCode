#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        int type, a, b, p;
        string str;
        cin >> type;
        if (type == 1)
        {
            cin >> str;
            s.append(str);
            cout << s << endl;
        }
        else if (type == 2)
        {
            cin >> a >> b;
            s = s.substr(a, b);
            cout << s << endl;
        }
        else if (type == 3)
        {
            cin >> a >> str;
            s.insert(a, str);
            cout << s << endl;
        }
        else
        {
            cin >> str;
            p = s.find(str);
            if (p == string::npos)
            {
                p = -1;
            }
            cout << p << endl;
        }
    }
    return 0;
}