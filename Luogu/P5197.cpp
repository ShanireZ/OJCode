#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int links[n + 1];
    memset(links, 0, sizeof(links));
    for (int i = 0; i < n - 1; i++)
    {
        int roadA, roadB;
        cin >> roadA >> roadB;
        links[roadA]++;
        links[roadB]++;
    }
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (links[i] > max)
        {
            max = links[i];
        }
    }
    cout << max + 1;
    return 0;
}