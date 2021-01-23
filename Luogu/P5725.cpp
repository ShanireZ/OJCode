#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num = 1;
    for (int hang = 1; hang <= n; hang++)
    {
        for (int lie = 1; lie <= n; lie++)
        {
            if (num < 10)
            {
                cout << 0;
            }
            cout << num;
            num++;
        }
        cout << endl;
    }
    cout << endl;
    num = 1;
    for (int hang = 1; hang <= n; hang++)
    {
        for (int lie = 1; lie <= n; lie++)
        {
            if (lie < n + 1 - hang)
            {
                cout << "  ";
            }
            else
            {
                if (num < 10)
                {
                    cout << 0;
                }
                cout << num;
                num++;
            }
        }
        cout << endl;
    }
    return 0;
}