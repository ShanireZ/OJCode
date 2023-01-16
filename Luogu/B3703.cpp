#include <iostream>
#include <string>
using namespace std;
string s, ns;
int q, l, r;
int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> q;
    while (q--)
    {
        cin >> l >> r;
        ns = s.substr(l - 1, r - l + 1);
        int pos = ns.size() - 1;
        while (pos >= 0 && --ns[pos] < 'a')
        {
            ns[pos] = 'z';
            pos--;
        }
        if (pos < 0)
        {
            ns = "NULL";
        }
        cout << ns << "\n"
             << ((s.find(ns) != string::npos) ? "Happy New Year!" : "Happy Chinese New Year!") << "\n";
    }
    return 0;
}