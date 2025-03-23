#include <algorithm>
#include <iostream>
using namespace std;
int cnt[15], a, c3, c2;
int main()
{
    for (int i = 1; i <= 7; i++)
    {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= 13; i++)
    {
        c3 += (cnt[i] >= 3);
        c2 += (cnt[i] >= 2);
    }
    cout << ((c2 > 1 && c3) ? "Yes" : "No") << endl;
    return 0;
}