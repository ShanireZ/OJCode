#include <algorithm>
#include <iostream>
using namespace std;
int cnt[1005], res[1005], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        ch == 'q' ? cnt[i - 1]++ : cnt[i + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        res[cnt[i]]++;
    }
    cout << res[0] << " " << res[1] << " " << res[2] << endl;
    return 0;
}