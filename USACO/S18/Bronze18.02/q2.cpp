#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream fin("hoofball.in");
ofstream fout("hoofball.out");
int main()
{
    int n;
    fin >> n;
    int cows[n];
    memset(cows, 0, sizeof(cows));
    for (int i = 0; i < n; i++)
    {
        fin >> cows[i];
    }
    sort(cows, cows + n);
    int targets[n];
    memset(targets, 0, sizeof(targets));
    targets[0] = 1;
    targets[n - 1] = n - 2;
    for (int i = 1; i < n - 1; i++)
    {
        if ((cows[i] - cows[i - 1]) > (cows[i + 1] - cows[i]))
        {
            targets[i] = i + 1;
        }
        else if ((cows[i] - cows[i - 1]) <= (cows[i + 1] - cows[i]))
        {
            targets[i] = i - 1;
        }
    }
    int receive[n];
    memset(receive, 0, sizeof(receive));
    for (int i = 0; i < n; i++)
    {
        receive[targets[i]]++;
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (receive[i] == 0)
        {
            total++;
        }
        if (targets[i] > i && targets[targets[i]] == i && receive[i] == 1 && receive[targets[i]] == 1)
        {
            total++;
        }
    }
    fout << total;
    return 0;
}