#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, op = 0;
    cin >> n;
    while (n--)
    {
        string s, s1, s2;
        cin >> s;
        if (isalpha(s[0]))
        {
            op = s[0] - 'a';
            cin >> s1 >> s2;
        }
        else
        {
            s1 = s;
            cin >> s2;
        }
        int len = s1.size() + s2.size() + 2;
        int n1 = stoi(s1), n2 = stoi(s2), n3 = 0;
        cout << n1;
        if (op == 0)
        {
            cout << "+";
            n3 = n1 + n2;
        }
        else if (op == 1)
        {
            cout << "-";
            n3 = n1 - n2;
        }
        else if (op == 2)
        {
            cout << "*";
            n3 = n1 * n2;
        }
        cout << n2 << "=" << n3 << endl;
        s = to_string(n3);
        cout << len + s.size() << endl;
    }
    return 0;
}