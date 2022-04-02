#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int p[11000005], pos = 1, ans;
char s[22000005];
void manacher()
{
    int mx = 0, mid = 0;
    for (int i = 0; i < pos; i++)
    {
        p[i] = (i < mx) ? min(p[mid * 2 - i], mx - i) : 1;
        while (i + p[i] < pos && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i];
            mid = i;
        }
        ans = max(ans, p[i]);
    }
}
int main()
{
    char ch = getchar();
    s[0] = '#';
    while (ch >= 'a' && ch <= 'z')
    {
        s[pos++] = ch;
        s[pos++] = '#';
        ch = getchar();
    }
    manacher();
    printf("%d\n", ans - 1);
    return 0;
}