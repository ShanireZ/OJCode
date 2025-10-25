#include <algorithm>
#include <iostream>
using namespace std;
int n, tot, pt, op;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cout << tot << " " << pt << endl;
            return 0;
        }
        else
        {
            tot++, pt += (op == 0);
        }
    }
    return 0;
}