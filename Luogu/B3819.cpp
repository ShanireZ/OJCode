#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> lst;
string s;
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        lst.insert(s);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> s;
        lst.erase(s);
    }
    for (int i = 1; i <= x; i++)
    {
        cin >> s;
        lst.insert(s);
    }
    for (string name : lst)
    {
        cout << name << endl;
    }
    return 0;
}