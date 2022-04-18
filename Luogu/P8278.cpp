#include <cstring>
#include <iostream>
using namespace std;
int ans[100005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        int n;
        cin >> n;
        int trig = 0, cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> ans[i];
            if (ans[i] == -1)
            {
                cnt++;
                trig = 1;
                ans[i] = ans[i - 1] + 1;
            }
            else if (ans[i] != -1 && trig)
            {
                int x = (ans[i] - ans[i - cnt]) / cnt;
                for (int j = 1; j < cnt; j++)
                {
                    ans[i - j] = ans[i - j + 1] - x;
                }
                cnt = 1, trig = 0;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] - ans[i - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}