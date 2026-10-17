#include <iostream>
using namespace std;
int lines[14]; //儲存棋盤每行中Queen所在列
int rows[14];  //儲存該列之前是否已經有Queen
int n, total;  //total為總情況數

void make(int line) //line為當前行號
{
    if (line > n) //n行放置完成
    {
        total++;        //情況數+1
        if (total <= 3) //若是前3種情況
        {
            for (int i = 1; i <= n; i++)
            {
                cout << lines[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (rows[i] == 1) //檢查該列上是否已經有Queen
        {
            continue;
        }
        int trig = 1;
        for (int j = 1; j < line; j++) //檢查現在放置的Queen是否在其他Queen的對角線上
        {
            if (lines[j] + (line - j) == i || lines[j] - (line - j) == i)
            {
                trig = 0;
                break;
            }
        }
        if (trig) //若新Queen不與之前列和對角線衝突
        {
            lines[line] = i; //放置Queen
            rows[i] = 1;     //標記槓放置的列
            make(line + 1);  //遞歸計算下一行
            rows[i] = 0;     //回溯
        }
    }
}

int main()
{
    cin >> n;
    make(1);
    cout << total;
    return 0;
}