#include <iostream>
#include <string>
using namespace std;
char tz[10], ch;
int main()
{
    tz[3] = 'a', tz[4] = 'c', tz[5] = 'g', tz[6] = 'w';
    int n, tot = 0;
    cin >> n;
    for (int i = 0; i < n * 8; i++)
    {
        cin >> ch;
        tot += ch - '0';
    }
    if (tot < n * 3 || tot > n * 6)
    {
        cout << "NIE\n";
        return 0;
    }
    int cnt = n;
    for (int i = 1; i <= n; i++)
    {
        int now = tot / cnt;
        cout << tz[now];
        tot -= now, cnt--;
    }
    return 0;
}