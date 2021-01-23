#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, bool> m;
int main()
{
    int n, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (m[s] == false)
        {
            tot++;
        }
        m[s] = true;
    }
    cout << tot;
    return 0;
}