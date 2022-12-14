#include <cstring>
#include <iostream>
using namespace std;
char s[1000005], t[1000005], ans[30];
int main()
{
    for (int i = 0; i < 26; i++)
    {
        ans[i] = i + 'a';
    }
    scanf("%s %s", s, t);
    int sz = min(strlen(s), strlen(t));
    for (int i = 0; i < sz; i++)
    {
        if (s[i] != t[i])
        {
            if (s[i] < t[i])
            {
                swap(ans[s[i] - 'a'], ans[t[i] - 'a']);
            }
            break;
        }
    }
    printf("%s\n", ans);
    return 0;
}