#include <algorithm>
#include <iostream>
using namespace std;
string s1, s2;
int n1, n2, d[1000005];
int main()
{
    cin >> s1 >> s2;
    n1 = s1.size(), n2 = s2.size();
    s2 += "#";
    for (int i = 1, j = 0; i < n2; i++)
    {
        while (j != 0 && s2[i] != s2[j])
        {
            j = d[j - 1];
        }
        j += (s2[i] == s2[j]);
        d[i] = j;
    }
    for (int i = 0, j = 0; i < n1; i++)
    {
        while (j != 0 && s1[i] != s2[j])
        {
            j = d[j - 1];
        }
        j += (s1[i] == s2[j]);
        if (j == n2)
        {
            cout << i - n2 + 2 << endl;
        }
    }
    for (int i = 0; i < n2; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}