#include <algorithm>
#include <iostream>
using namespace std;
int add[1000005], red[1000005];
int main()
{
    int n, flag = 0, tot = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        add[a]++, red[b]++;
    }
    for (int i = 1; i <= 1000000; i++)
    {
        tot += add[i];
        if (tot && flag == 0)
        {
            flag = 1;
            cout << i << " ";
        }
        tot -= red[i];
        if (tot == 0 && flag == 1)
        {
            flag = 0;
            cout << i << endl;
        }
    }
    return 0;
}