#include <iostream>
using namespace std;
int main()
{
    int save = 0, have = 0, cost, month = 1;
    while(month <= 12)
    {
        have = have + 300;
        cin >> cost;
        have = have - cost;
        if(have < 0)
        {
            cout << -month;
            return 0;
        }
        save = save + (have - have % 100);
        have = have % 100;
        month++;
    }
    cout << have + save * 1.2;
    return 0;
}