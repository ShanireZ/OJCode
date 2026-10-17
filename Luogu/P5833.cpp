#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    // freopen("lineup.in", "r", stdin);
    // freopen("lineup.out", "w", stdout);
    // ios::sync_with_stdio(false);
    //!手動先排個字典序最小情況，用sort自動排也可
    string names[10] = {"", "Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    string rules[10][2];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> rules[i][0] >> rules[i][1] >> rules[i][1] >> rules[i][1] >> rules[i][1] >> rules[i][1];
    }
    while (true)
    {
        int trig = 1;
        for (int i = 1; i <= n; i++) //!檢查當前的排列是否滿足每條規則
        {
            int rk1, rk2;
            for (int j = 1; j <= 8; j++) //!搜尋第i條規則中的兩隻奶牛在排列中的位置
            {
                if (names[j] == rules[i][0])
                {
                    rk1 = j;
                }
                else if (names[j] == rules[i][1])
                {
                    rk2 = j;
                }
            }
            if (abs(rk1 - rk2) != 1) //!如果不相鄰
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            for (int i = 1; i <= 8; i++)
            {
                cout << names[i] << endl;
            }
            return 0;
        }
        next_permutation(names + 1, names + 1 + 8); //下一個排列
    }
    return 0;
}