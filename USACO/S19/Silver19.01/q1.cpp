#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("planting.in");
ofstream fout("planting.out");

int main()
{
    int n;
    fin >> n;
    int links[n + 1];
    memset(links, 0, sizeof(links));
    for (int i = 0; i < n - 1; i++)
    {
        int roadA, roadB;
        fin >> roadA >> roadB;
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
    fout << max + 1;
    return 0;
}