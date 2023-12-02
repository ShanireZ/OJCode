#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int d[1000005], sz1, sz2;
void border()
{
    for (int i = 1, j = 0; i < sz2; i++)
    {
        while (j != 0 && s2[i] != s2[j])
        {
            j = d[j - 1];
        }
        d[i] = (s2[i] == s2[j] ? ++j : j);
    }
}
void kmp()
{
    int p1 = 0, p2 = 0;
    while (p1 < sz1)
    {
        while (p1 < sz1 && p2 < sz2 && s1[p1] == s2[p2])
        {
            p1++, p2++;
        }
        if (p2 == sz2)
        {
            cout << p1 - p2 + 1 << endl;
        }
        p2 == 0 ? p1++ : p2 = d[p2 - 1];
    }
}
int main()
{
    cin >> s1 >> s2;
    sz1 = s1.size(), sz2 = s2.size();
    border(), kmp();
    for (int i = 0; i < sz2; i++)
    {
        cout << d[i] << " ";
    }
    return 0;
}