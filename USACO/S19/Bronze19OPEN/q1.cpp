#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int rocki, rockj, lakei, lakej, burni, burnj;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'B')
            {
                burni = i, burnj = j;
            }
            else if (tmp == 'R')
            {
                rocki = i, rockj = j;
            }
            else if (tmp == 'L')
            {
                lakei = i, lakej = j;
            }
        }
    }
    int dis;
    if (lakei != burni && lakej != burnj)
    {
        dis = abs(lakei - burni) + abs(lakej - burnj) - 1;
    }
    else if (lakei == burni)
    {
        dis = abs(lakej - burnj) - 1;
        int left = min(lakej, burnj);
        int right = max(lakej, burnj);
        if (rocki == lakei && rockj < right && rockj > left)
        {
            dis += 2;
        }
    }
    else
    {
        dis = abs(lakei - burni) - 1;
        int left = min(lakei, burni);
        int right = max(lakei, burni);
        if (rockj == lakej && rocki < right && rocki > left)
        {
            dis += 2;
        }
    }
    cout << dis;
    return 0;
}