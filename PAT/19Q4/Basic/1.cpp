#include <iostream>
using namespace std;
int all[1005];
int main()
{
    int n;
    cin >> n;
    all[1] = 2;
    all[3] = 1;
    all[4] = 9;
    for (int i = 5; i <= n; i++)
    {
        all[i] = (all[i - 1] + all[i - 2] + all[i - 3] + all[i - 4]) % 10;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << all[i];
    }
    return 0;
}