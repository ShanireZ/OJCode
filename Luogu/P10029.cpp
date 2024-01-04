#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m, p;
        cin >> n >> m >> p;
        if (m < p)
        {
            cout << "Alice" << endl;
        }
        else if (n < p)
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Lasting Battle" << endl;
        }
    }
    return 0;
}