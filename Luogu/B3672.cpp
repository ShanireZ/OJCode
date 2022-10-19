#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int main()
{
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        while (s.size())
        {
            m[s]++, s = s.substr(1);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int k;
        cin >> k >> s;
        cout << m[s] << "\n";
    }
    return 0;
}