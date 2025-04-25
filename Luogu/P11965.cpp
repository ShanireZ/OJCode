#include <algorithm>
#include <iostream>
using namespace std;
long long cnt[70000000], n, ans, state;
string s;
int main()
{
    cin >> n >> s;
    cnt[0] = 1;
    for (char ch : s)
    {
        int id = ch - 'a';
        state ^= (1 << id); // 统计每个字母出现次数的奇偶性
        ans += cnt[state];  // 必须全为偶数才能消除
        cnt[state]++;
    }
    cout << ans << endl;
    return 0;
}