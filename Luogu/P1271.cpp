#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
int a[1000];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int id;
        cin >> id;
        a[id]++;
    }
    for(int i = 1; i <= n; i++)
    {
        int sum = a[i];
        for(int j = 1; j <= sum; j++)
        {
            cout << i << " ";
        }
    }
    return 0;
}