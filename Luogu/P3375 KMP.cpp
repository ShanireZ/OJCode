#include <cstdio>
#include <string>
using namespace std;
string s1, s2;
int jp[30], d[1000005], sz1, sz2;
void border() //! 求D数组
{
    for (int i = 1, j = 0; i < sz2; i++)
    {
        while (j > 0 && s2[i] != s2[j])
        {
            j = d[j - 1];
        }
        if (s2[i] == s2[j])
        {
            j++;
        }
        d[i] = j;
    }
}
void kmp()
{
    int i = 0, j = 0;
    while (i < sz1)
    {
        while (i < sz1 && j < sz2 && s1[i] == s2[j]) //! 尝试匹配
        {
            i++, j++;
            if (j == sz2) //! P完全匹配输出起始位置
            {
                printf("%d\n", i - j + 1);
            }
        }
        (j == 0) ? i++ : j = d[j - 1]; //! 匹配失败跳出 或 匹配完毕跳出
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
    border();
    kmp();
    for (int i = 0; i < sz2; i++)
    {
        printf("%d ", d[i]);
    }
    return 0;
}