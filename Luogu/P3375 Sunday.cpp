#include <cstdio>
#include <string>
using namespace std;
string s1, s2;
int jp[30], pre[1000005], sz1, sz2;
void border()
{
    printf("%d ", pre[0]);
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
        printf("%d ", pre[i]);
    }
}
void sunday()
{
    for (int i = 0; i < 26; i++)
    {
        jp[i] = sz2 + 1;
    }
    for (int i = 0; i < sz2; i++)
    {
        int id = s2[i] - 'A';
        jp[id] = sz2 - i;
    }
    int i = 0, j = 0;
    while (i + sz2 <= sz1)
    {
        while (j < sz2 && s1[i + j] == s2[j])
        {
            j++;
        }
        if (j == sz2)
        {
            printf("%d\n", i + 1);
        }
        if (i + sz2 >= sz1)
        {
            break;
        }
        int id = s1[i + sz2] - 'A';
        i += jp[id];
        j = 0;
    }
}
int main()
{
    char ch = getchar();
    while (ch >= 'A' && ch <= 'Z')
    {
        s1 += ch;
        ch = getchar();
    }
    while (ch > 'Z' || ch < 'A')
    {
        ch = getchar();
    }
    while (ch >= 'A' && ch <= 'Z')
    {
        s2 += ch;
        ch = getchar();
    }
    sz1 = s1.size(), sz2 = s2.size();
    sunday();
    border();
    return 0;
}