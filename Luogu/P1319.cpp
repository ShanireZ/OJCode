#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int p = 1, ot = 0, num;
    while (cin >> num)
    {
        for (int i = 1; i <= num; i++)
        {
            cout << ot;
            p++;
            if (p > n)
            {
                cout << endl;
                p = 1;
            }
        }
        ot = !ot;
    }
    return 0;
}