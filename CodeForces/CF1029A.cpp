#include <iostream>
#include <string>
using namespace std;
int n, k, d[100];
string s, ans;
void kmp_pre()
{
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j > 0 && s[i] != s[j])
        {
            j = d[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        d[i] = j;
    }
}
int main()
{
    cin >> n >> k >> s;
    kmp_pre();
    ans = s;
    for (int i = 2; i <= k; i++)
    {
        ans += s.substr(d[n - 1]);
    }
    cout << ans;
    return 0;
}