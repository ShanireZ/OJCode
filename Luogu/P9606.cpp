#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string str;
int p[800005], n;
char s[800005];
int main()
{
    cin >> n >> str;
    int pos = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        s[++pos] = '#';
        s[++pos] = str[i];
    }
    s[++pos] = '#';
    for (int i = 1, mx = 0, mid = 0; i <= pos; i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i + p[i] <= pos && i - p[i] >= 1 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        if (mx > pos)
        {
            ans = i; // 找到第一个右端到末尾的回文子串，以其为中心整体回文最短
            break;
        }
    }
    cout << (ans * 2 - 1) / 2 - n << endl;
    return 0;
}
// TAG: Manacher 最长回文子串 贪心