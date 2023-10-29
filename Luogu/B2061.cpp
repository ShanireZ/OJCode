#include <iostream>
using namespace std;
int main()
{
    int k, tot1 = 0, tot5 = 0, tot10 = 0;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            tot1++;
        }
        if (x == 5)
        {
            tot5++;
        }
        if (x == 10)
        {
            tot10++;
        }
    }
    cout << tot1 << endl;
    cout << tot5 << endl;
    cout << tot10 << endl;
    return 0;
}