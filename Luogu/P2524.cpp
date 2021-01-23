#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    string s, now;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        now.append(1, '0' + i);
    }
    int ans = 1;
    while (now != s)
    {
        next_permutation(now.begin(), now.end());
        ans++;
    }
    cout << ans;
    return 0;
}