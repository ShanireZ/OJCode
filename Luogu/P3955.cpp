#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int books[1005];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }
    sort(books, books + n);
    for (int i = 0; i < q; i++)
    {
        int len, id, tmp, trig = 1;
        cin >> len >> id;
        tmp = pow(10, len);
        for (int j = 0; j < n; j++)
        {
            if (books[j] % tmp == id)
            {
                cout << books[j] << endl;
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}