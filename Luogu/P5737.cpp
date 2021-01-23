#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tot;
vector<int> all;
void check(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        tot++;
        all.push_back(year);
    }
}
int main()
{
    int x, y;
    cin >> x >> y;
    if (x % 4 != 0)
    {
        x = x + (4 - x % 4);
    }
    for (int i = x; i <= y; i += 4)
    {
        check(i);
    }
    cout << tot << endl;
    for (int i = 0; i < all.size(); i++)
    {
        cout << all[i] << " ";
    }
    return 0;
}