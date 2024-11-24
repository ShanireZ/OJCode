#include <algorithm>
#include <iostream>
using namespace std;
int cnt[10], cd[10];
int main()
{
    int x, n;
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cd[1] >> cd[2] >> cd[3] >> cd[4] >> cd[5];
        sort(cd + 1, cd + 6);
        for (int j = 5; j >= 1; j++)
        {
            if (x >= cd[j])
            {
                x -= cd[j];
                cnt[cd[j]]++;
                break;
            }
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    cout << x << endl;
    return 0;
}