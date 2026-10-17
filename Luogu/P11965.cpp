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
        state ^= (1 << id); // 統計每個字母出現次數的奇偶性
        ans += cnt[state];  // 必須全為偶數才能消除
        cnt[state]++;
    }
    cout << ans << endl;
    return 0;
}