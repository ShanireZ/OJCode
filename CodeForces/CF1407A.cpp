#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int times = 1; times <= t; times++)
    {
        int n, tot1 = 0, tot0 = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int num;
            cin >> num;
            if (num == 0)
            {
                tot0++;
            }
            else
            {
                tot1++;
            }
        }
        if (tot0 >= n / 2)
        {
            cout << tot0 << endl;
            for (int i = 1; i <= tot0; i++)
            {
                cout << 0 << " ";
            }
            cout << endl;
        }
        else
        {
            if (tot1 % 2 == 1)
            {
                tot1--;
            }
            cout << tot1 << endl;
            for (int i = 1; i <= tot1; i++)
            {
                cout << 1 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}