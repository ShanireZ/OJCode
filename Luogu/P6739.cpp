#include <iostream>
#include <string>
using namespace std;
string s, h1, h2;
int main()
{
    int n;
    cin >> n >> s;
    if (n % 2 == 0)
    {
        cout << "NOT POSSIBLE" << endl;
        return 0;
    }
    int m = n / 2;
    h1 = s.substr(0, m);
    int i = 0, j = m, cnt = 0;
    while (i < m && j < n)
    {
        if (h1[i] == s[j])
        {
            i++;
        }
        j++;
    }
    if (i == m)
    {
        cnt = 1;
    }
    h2 = s.substr(m + 1);
    i = j = 0;
    while (i < m && j <= m)
    {
        if (h2[i] == s[j])
        {
            i++;
        }
        j++;
    }
    if (i == m)
    {
        cnt += 2;
    }
    if (cnt == 0)
    {
        cout << "NOT POSSIBLE" << endl;
    }
    else if (cnt == 1)
    {
        cout << h1 << endl;
    }
    else if (cnt == 2 || h1 == h2)
    {
        cout << h2 << endl;
    }
    else
    {
        cout << "NOT UNIQUE" << endl;
    }
    return 0;
}