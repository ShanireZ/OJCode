#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string all[30];
bool cmp(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> all[i];
    }
    sort(all + 1, all + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << all[i];
    }
    return 0;
}