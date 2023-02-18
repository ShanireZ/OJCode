#include <algorithm>
#include <iostream>
using namespace std;
int times[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i];
        times[i] = times[i] / 2 - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << 'R';
        while (times[i] > times[i + 1])
        {
            int now = i;
            while (times[now] > times[now + 1])
            {
                cout << 'L';
                times[now]--;
                now--;
            }
            while (now != i)
            {
                cout << 'R';
                now++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << 'L';
    }
    cout << "\n";
    return 0;
}