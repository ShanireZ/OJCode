#include <algorithm>
#include <iostream>
using namespace std;
char chs[5];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> chs[1] >> chs[2] >> chs[3] >> chs[4];
        sort(chs + 1, chs + 5);
        int ans = 3;
        if (chs[1] == chs[2])
        {
            ans--;
        }
        if (chs[3] == chs[4])
        {
            ans--;
        }
        if (chs[2] == chs[3])
        {
            ans--;
        }
        cout << ans << endl;
    }
    return 0;
}