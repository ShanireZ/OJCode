#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int n;
    fin >> n;
    int times[1001];
    memset(times, 0, sizeof(times));
    for (int i = 0; i < n; i++)
    {
        int start, end, buckets;
        fin >> start >> end >> buckets;
        for(int j = start; j <= end; j++)
        {
            times[j] += buckets;
        }
    }
    int max_buckets = 0;
    for(int i = 0; i < 1001; i++)
    {
        max_buckets = max(max_buckets, times[i]);
    }
    fout << max_buckets;
    return 0;
}