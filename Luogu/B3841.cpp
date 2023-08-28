#include <algorithm>
#include <iostream>
using namespace std;
long long nums[20], pw[20][20];
int main()
{
    for (int i = 1; i < 10; i++)
    {
        pw[i][0] = 1;
        for (int j = 1; j < 10; j++)
        {
            pw[i][j] = pw[i][j - 1] * i;
        }
    }
    int n;
    cin >> n;
    while (n--)
    {
        long long x;
        cin >> x;
        long long tmp = x, tot = 0, cnt = 0;
        while (tmp)
        {
            nums[++cnt] = tmp % 10;
            tmp /= 10;
        }
        for (int i = 1; i <= cnt; i++)
        {
            tot += pw[nums[i]][cnt];
        }
        if (tot == x)
        {
            cout << "T" << endl;
        }
        else
        {
            cout << "F" << endl;
        }
    }
    return 0;
}
// TAG: 模拟 GESP2