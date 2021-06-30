#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string s;
int p[22000005], ans = 1;
void manacher()
{
    int mid = 0, mx = 0;
    for (int i = 0; i < s.size(); i++)
    {
    	p[i] = (i < mx) ? min(mx - i, p[2 * mid - i]) : 1;
        while (i + p[i] < s.size() && i - p[i] >= 0 && s[i + p[i]] == s[i - p[i]])
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
    while (ch >= 'a' && ch <= 'z')
    {
        s.append("#").append(1, ch);
        ch = getchar();
    }
    s.append("#");
    manacher();
    printf("%d", ans - 1);
    return 0;
}