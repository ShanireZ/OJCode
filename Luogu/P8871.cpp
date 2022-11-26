#include <cmath>
#include <iostream>
#include <string>
using namespace std;
string s[20005];
int main()
{
    int m = 1;
    while (getline(cin, s[m]))
    {
        m++;
    }
    int t = log10(--m) + 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j + log10(i) < t; j++)
        {
            cout << ' ';
        }
        cout << i << ' ' << s[i] << '\n';
    }
    return 0;
}