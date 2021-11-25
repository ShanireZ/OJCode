#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n[10];
int main()
{
    for(int i = 1; i <= 7; i++)
    {
        cin >> n[i];
    }
    sort(n + 1, n + 1 + 7);
    cout << n[1] << " " << n[2] << " " << n[7] - n[1] - n[2];
    return 0;
}