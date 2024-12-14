#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int ex[5] = {90, 80, 60, 0, 0}, cnt[5] = {0, 0, 0, 0, 0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 0; j < 4; j++)
        {
            if (s >= ex[j])
            {
                cnt[j]++;
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}