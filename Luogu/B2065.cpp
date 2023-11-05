#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n, t, ok;
    cin >> n >> t >> ok;
    double jwj = 1.0 * ok / t;
    for (int i = 2; i <= n; i++)
    {
        int tt, ook;
        cin >> tt >> ook;
        double now = 1.0 * ook / tt;
        if (now - jwj > 0.05)
        {
            cout << "better" << endl;
        }
        else if (jwj - now > 0.05)
        {
            cout << "worse" << endl;
        }
        else
        {
            cout << "same" << endl;
        }
    }
    return 0;
}