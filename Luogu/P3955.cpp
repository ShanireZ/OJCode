#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int book[1005];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> book[i];
    }
    sort(book + 1, book + 1 + n);
    for (int i = 1; i <= q; i++)
    {
        int len, id, ok = -1;
        cin >> len >> id;
        for (int j = 1; j <= n; j++)
        {
            int x = pow(10, len);
            if (book[j] % x == id)
            {
                ok = book[j];
                break;
            }
        }
        cout << ok << endl;
    }
    return 0;
}