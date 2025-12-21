#include <algorithm>
#include <iostream>
using namespace std;
string fw = "ESWN";
char f[15];
int T, n, step[15];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> f[i] >> step[i];
        }
        cout << n + n - 1 << " " << f[1] << endl;
        int pre = fw.find(f[1]);
        for (int i = 1; i <= n; i++)
        {
            if (i != 1)
            {
                int now = fw.find(f[i]);
                if (now - pre == 1 || now - pre == -3)
                {
                    cout << "R" << endl;
                }
                else
                {
                    cout << "L" << endl;
                }
                pre = now;
            }
            cout << "Z " << step[i] << endl;
        }
    }
    return 0;
}