#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int jp[30], pre[1000005], sz1, sz2;
void border()
{
    for (int i = 1, k = 0; i < sz2; i++)
    {
        while (s2[i] != s2[k] && k > 0)
        {
            k = pre[k - 1];
        }
        if (s2[i] == s2[k])
        {
            k++;
        }
        pre[i] = k;
    }
}
void horspool()
{
    for (int i = 0; i < 26; i++)
    {
        jp[i] = sz2;
    }
    for (int i = 0; i < sz2 - 1; i++)
    {
        int id = s2[i] - 'A';
        jp[id] = sz2 - 1 - i;
    }
    int i = sz2 - 1, j = sz2 - 1;
    while (i < sz1)
    {
        int x = 0;
        while (x <= sz2 - 1 && s1[i - x] == s2[j - x])
        {
            x++;
        }
        if (x == sz2)
        {
            printf("%d\n", i - j + 1);
        }
        int id = s1[i] - 'A';
        i += jp[id];
    }
}
int main()
{
    cin >> s1 >> s2;
    sz1 = s1.size(), sz2 = s2.size();
    horspool();
    border();
    for (int i = 0; i < sz2; i++)
    {
        printf("%d ", pre[i]);
    }
    return 0;
}