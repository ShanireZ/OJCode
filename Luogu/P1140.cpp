#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a, b;
int points[105][105];
int rule[5][5] = {
    //-  A  C  G  T
    {0, -3, -4, -2, -1},  //-
    {-3, 5, -1, -2, -1},  //A
    {-4, -1, 5, -3, -2},  //C
    {-2, -2, -3, 5, -2},  //G
    {-1, -1, -2, -2, 5}}; //T
int choose(char x)
{
    int n;
    if (x == 'A')
    {
        n = 1;
    }
    else if (x == 'C')
    {
        n = 2;
    }
    else if (x == 'G')
    {
        n = 3;
    }
    else
    {
        n = 4;
    }
    return n;
}
int main()
{
    int alen, blen;
    cin >> alen >> a >> blen >> b;
    for (int i = 1; i <= blen; i++) //a取0個，b取i個，對齊a b需要i個操作
    {
        points[0][i] = points[0][i - 1] + rule[0][choose(b[i - 1])];
    }
    for (int i = 1; i <= alen; i++) //a取i個，b取0個,對齊a b需要i個操作
    {
        points[i][0] = points[i - 1][0] + rule[choose(a[i - 1])][0];
    }
    for (int i = 1; i <= alen; i++)
    {
        for (int j = 1; j <= blen; j++) //逐位嘗試對齊，統計最小操作次數
        {
            int ni = choose(a[i - 1]);
            int nj = choose(b[j - 1]);
            int temp = max(points[i - 1][j] + rule[ni][0], points[i][j - 1] + rule[0][nj]); //b增加- 或 a增加-
            points[i][j] = max(temp, points[i - 1][j - 1] + rule[ni][nj]);                  //直接對照
        }
    }
    cout << points[alen][blen];
    return 0;
}