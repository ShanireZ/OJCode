#include <algorithm>
#include <iostream>
using namespace std;
int a[10], b[10], ok;
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        cin >> a[i];
        b[i] = i;
    }
    for (int i = 2; i <= 5 && ok == 0; i++)
    {
        swap(a[i], a[i - 1]), ok = 1;
        for (int j = 1; j <= 5 && ok; j++)
        {
            if (a[j] != b[j])
            {
                ok = 0;
            }
        }
        swap(a[i], a[i - 1]);
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}