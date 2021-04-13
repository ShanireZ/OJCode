#include <iostream>
using namespace std;
int main()
{
    int n, now, pre = 0, cnt = 0, trig = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> now;
        if (now < pre && trig == 1)
        {
            trig = 2;
        }
        else if (now > pre && trig == 2)
        {
            trig = 1;
            cnt++;
        }
        pre = now;
    }
    cout << cnt << endl;
    return 0;
}