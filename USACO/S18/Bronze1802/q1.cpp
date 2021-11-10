#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
ifstream fin("teleport.in");
ofstream fout("teleport.out");
int main()
{
    int a, b, x, y;
    fin >> a >> b >> x >> y;
    int distance = abs(a - b);
    int distanceX = abs(a - x) + abs(b - y);
    int distanceY = abs(a - y) + abs(b - x);
    int minDis = min(distanceX, distanceY);
    minDis = min(minDis, distance);
    fout << minDis;
    return 0;
}