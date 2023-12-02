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
    for (int i = 0, j = 0; i < sz1;)
    {
        while (i < sz1 && j < sz2 && s1[i] == s2[j])
        {
            i++, j++;
        }
        if (j == sz2)
        {
            cout << i - j + 1 << endl;
        }
        j == 0 ? i++ : j = d[j - 1];
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
// TAG: KMP border AC自动机