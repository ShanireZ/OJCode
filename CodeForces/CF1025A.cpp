#include <iostream>
using namespace std;
int t[26];
int main()
{
    int n, ok = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        t[ch - 'a']++;
        if (t[ch - 'a'] >= 2)
        {
            ok = 1;
        }
    }
    cout << ((ok || n == 1) ? "Yes" : "No") << endl;
    return 0;
}