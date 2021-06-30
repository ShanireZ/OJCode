#include <iostream>
using namespace std;
char chs[5] = {'0', 'M', 'C', 'O', 'I'};
long long ts[5], ans;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= 4; j++)
        {
            if (str[0] == chs[j])
            {
                ts[j]++;
                break;
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = i + 1; j <= 4; j++)
        {
            for (int k = j + 1; k <= 4; k++)
            {
                ans += ts[i] * ts[j] * ts[k];
            }
        }
    }
    cout << ans;
    return 0;
}