#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int n, c1, c2;
int main()
{
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
        {
            continue;
        }
        (s[i] == 'R' && t[i] == 'S') || (s[i] == 'S' && t[i] == 'P') || (s[i] == 'P' && t[i] == 'R') ? c1++ : c2++;
    }
    cout << c1 << " " << c2 << endl;
    return 0;
}