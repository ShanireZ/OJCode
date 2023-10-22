#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <string>
using namespace std;
mt19937 rnd(time(0));
map<long long, long long> cnt;
char chs[2000005];
long long ex[2000005], n, ans, now, pos;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ex[i] = rnd();
    }
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (pos && chs[pos] == ch)
        {
            now ^= ex[pos] * ch;
            pos--;
        }
        else
        {
            chs[++pos] = ch;
            now ^= ex[pos] * ch;
        }
        ans += cnt[now];
        cnt[now]++;
    }
    cout << ans << endl;
    return 0;
}