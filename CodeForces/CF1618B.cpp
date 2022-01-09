#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sz, t = 1;
        string now, pre;
        cin >> sz >> now;
        cout << now;
        pre = now;
        for (int i = 2; i <= sz - 2; i++)
        {
            cin >> now;
            if (now[0] != pre[1])
            {
                t = 0;
                cout << now[0];
            }
            cout << now[1];
            pre = now;
        }
        if (t)
        {
            cout << "a";
        }
        cout << endl;
    }
    return 0;
}